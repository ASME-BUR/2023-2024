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


    def yolo_callback(self, msg):
        self.detections = msg.detected

        if not self.frame:
            return
        

    def view_detections(self):
        while not self.frame or self.detections:
            time.sleep(0.5)
        
        for detection in self.detections:
            cv2.rectangle(self.frame,
                (detection.bbox.pose.position.x - detection.width/2, detection.bbox.pose.position.y - detection.height/2),
                (detection.bbox.pose.position.x + detection.width/2, detection.bbox.pose.position.y + detection.height/2),
                (0,255,0),2)
            cv2.putText(self.frame,f'{detection.label}',
                (detection.bbox.pose.position.x + detection.width/2 + 10, detection.bbox.pose.position.y + detection.height/2),
                0,0.3,(0,255,0))

        while True:
            cv2.imshow("preview", self.frame)
            key = cv2.waitKey(20)
            if key == 27: # exit on ESC
                break

def main(args=None):
    rclpy.init(args=args)

    detection_viewer = DetectionViewer()

    # rospy.Timer(rospy.Duration(1.0), detection_viewer.view_detections)

    # rclpy.spin(detection_viewer)
    detection_viewer.view_detections()

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    detection_viewer.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()