import cv2
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from std_msgs.msg import String
import torch

frame_counter = 0  # global counter for frame


class YoloNode(Node):
    def __init__(self):
        super().__init__("yolo_node")
        self.model = torch.hub.load(
            "ultralytics/yolov5", "yolov5s"
        )  # Can be 'yolov5n' - 'yolov5x6', or 'custom'
        self.publisher_ = self.create_publisher(String, "yolo_detections", 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.detect_callback)
        self.i = 0

        # Create the subscriber. This subscriber will receive an Image
        # from the video_frames topic. The queue size is 10 messages.
        self.subscriber = self.create_subscription(
            Image,
            "/zed/zed_node/rgb_raw/image_raw_color",
            self.video_callback,
            rclpy.qos.qos_profile_sensor_data,
        )
        self.subscriber  # prevent unused variable warning
        self.frame = []

    def video_callback(self, msg):
        bridge = CvBridge()
        self.frame = bridge.imgmsg_to_cv2(msg, "bgr8")

    def detect_callback(self):
        msg = String()
        msg.data = "Hello World: %d" % self.i
        self.publisher_.publish(msg)
        # self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1

    def detect(self, model):
        # Inference on images
        img = "https://ultralytics.com/images/zidane.jpg"  # Can be a file, Path, PIL, OpenCV, numpy, or list of images
        # Run inference
        results = self.model(img)
        # Display results
        results.show()  # Other options: .show(), .save(), .crop(), .pandas(), etc.


def main():
    rclpy.init()
    node = YoloNode()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
