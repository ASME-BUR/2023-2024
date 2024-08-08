import sys
sys.path.append("/home/bur/2023-2024/ros2_ws/src/yolo/yolo")
import time
import cv2
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, PointCloud2
import sensor_msgs_py.point_cloud2 as pc2
import sensor_msgs.msg as sensor_msgs
from cv_bridge import CvBridge
from std_msgs.msg import String, Int32MultiArray, Float32MultiArray
from geometry_msgs.msg import PoseArray, Pose
import torch
import numpy as np
from yolo_msgs.msg import CVDetection, CVDetections


class YoloNode(Node):
    def __init__(self):
        super().__init__("yolo_node")
        # SET UP MODEL 
        self.model = torch.hub.load("ultralytics/yolov5", "custom", "best_new.pt") 
        self.model_classes = self.model.names
        self.device = 'cuda' if torch.cuda.is_available() else 'cpu'
        print("Used ", self.device)    
 
        self.img_subscriber = self.create_subscription(
            Image,
            "/zed/zed_node/rgb_raw/image_raw_color",
            self.video_callback,
            rclpy.qos.qos_profile_sensor_data,
        )
        self.img_subscriber  # prevent unused variable warning

        # self.depth_subscriber = self.create_subscription(
        #     PointCloud2,
        #     "/zed/zed_node/point_cloud/cloud_registered",
        #     self.depth_callback,
        #     rclpy.qos.qos_profile_sensor_data,
        # )
        # self.depth_subscriber  # prevent unused variable warning

        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.frame_forward_callback)

        # CREATE PUBLISHER OF CLASS LABEL WITH DISTANCE TO CENTER, CROPPED CLOUD, 
        self.yolo_publisher = self.create_publisher(CVDetections, "yolo_detections", 10)

        self.detect_results = ""
        self.frame = [] 
        self.depth = [] 

    def video_callback(self, msg):
        bridge = CvBridge()
        self.frame = bridge.imgmsg_to_cv2(msg, "bgr8")

    def getXYZ_from_pixel(self, x, y, my_pcl):
        arrayPosition = y*my_pcl.row_step + x*my_pcl.point_step
        arrayPosX = arrayPosition + my_pcl.fields[0].offset; # X has an offset of 0
        arrayPosY = arrayPosition + my_pcl.fields[1].offset; # Y has an offset of 4
        arrayPosZ = arrayPosition + my_pcl.fields[2].offset; # Z has an offset of 8
    
        X = my_pcl.data[arrayPosX]
        Y = my_pcl.data[arrayPosY]
        Z = my_pcl.data[arrayPosZ]

        return (X, Y, Z)

    def depth_callback(self, msg):
        height, width, channels = self.frame.shape
        self.depth = [[(0, 0, 0) for _ in range(width)] for _ in range(height)]
        for y in range(height):
            for x in range(width):
                pixel_value = self.getXYZ_from_pixel(x, y, msg)
                self.depth[y][x] = pixel_value
        self.crop_depth(self.detect_results)

    def frame_forward_callback(self):
        # Create messages for labels, bounding boxes, and confidence scores
        msg = CVDetections()

        if self.frame is None or len(self.frame) == 0:
            print("Error: The frame is empty or not properly initialized.")
            return

        results = self.model(self.frame)
        detections = results.pandas().xyxy[0]
        print(detections)

        # Extract labels and publish them
        labels = detections['class'].astype(int).tolist()
        print(labels)

        # Extract bounding boxes and confidence scores, then publish them
        poses = []
        confs = []
        cord = []

        idx = 0
        for _, entry in detections.iterrows():
            x_min, y_min, x_max, y_max, conf = entry[:5]
            x_center = (x_min + x_max) / 2
            y_center = (y_min + y_max) / 2
            width = x_max - x_min
            height = y_max - y_min

            pose = Pose()
            pose.position.x = x_center
            pose.position.y = y_center
            pose.position.z = 0.0  # Assuming you don't need Z dimension for bounding boxes
            pose.orientation.x = width
            pose.orientation.y = height
            pose.orientation.z = 0.0
            pose.orientation.w = 0.0

            cord.append([x_min, y_min, x_max, y_max])

            msg.detected.append(CVDetection())
            msg[idx].label = labels[idx]
            msg[idx].bbox = pose
            msg[idx].conf = conf
            msg[idx].width = width
            msg[idx].height = height

            idx += 1

        # Publish bounding boxes and confidence scores
        self.yolo_publisher.publish(msg)

        # Update model and detection results
        self.model.to(self.device)
        self.detect_results = labels, cord

    def class_to_labels(self, x):
        return self.model_classes[int(x)]
    
    def crop_depth(self, results):
        cropped_results = [] # all detections
        labels, cord = results
        n = len(labels)
        x_shape, y_shape = self.frame.shape[1], self.frame.shape[0]
        for i in range(n):
            row = cord[i]
            if row[4] >= 0.2: # confidence more than 20%
                bgr = (255, 0, 0)
                x1, y1, x2, y2 = int(row[0]*x_shape), int(row[1]*y_shape), int(row[2]*x_shape), int(row[3]*y_shape)
                # top left to bottom right pixels
                cropped = self.depth[y1:y2, x1:x2]
                cropped_results.append(cropped)

        return cropped_results

def main():
    rclpy.init()
    node = YoloNode()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
