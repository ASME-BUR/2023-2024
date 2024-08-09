import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge
import time

from geometry_msgs.msg import Pose
from sensor_msgs.msg import Image, PointCloud2
from yolo_msgs.msg import CVDetection, CVDetections


class DetectionViewer(Node):

    def __init__(self):
        super().__init__('detection_viewer')
        self.yolo_subscriber = self.create_subscription(
            CVDetections,
            'yolo_detections',
            self.yolo_callback, 10)
        self.img_subscriber = self.create_subscription(
            Image,
            "/zed/zed_node/rgb_raw/image_raw_color",
            self.video_callback,
            rclpy.qos.qos_profile_sensor_data,
        )

        self.frame = None
        self.detections = None


    def video_callback(self, msg):
        bridge = CvBridge()
        self.frame = bridge.imgmsg_to_cv2(msg, "bgr8")

        if self.detections:
            for detection in self.detections:
                cv2.rectangle(self.frame,
                    (int(detection.bbox.pose.position.x - detection.width/2), int(detection.bbox.pose.position.y - detection.height/2)),
                    (int(detection.bbox.pose.position.x + detection.width/2), int(detection.bbox.pose.position.y + detection.height/2)),
                    (0,255,0),2)
                # cv2.putText(self.frame,f'{detection.label}',
                #     (detection.bbox.pose.position.x + detection.width/2 + 10, detection.bbox.pose.position.y + detection.height/2),
                #     0,0.3,(0,255,0))
        
        cv2.imshow("preview", self.frame)
        key = cv2.waitKey(20)

    def yolo_callback(self, msg):
        self.detections = msg.detected


def main(args=None):
    rclpy.init(args=args)

    detection_viewer = DetectionViewer()

    rclpy.spin(detection_viewer)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    detection_viewer.destroy_node()
    rclpy.shutdown()
