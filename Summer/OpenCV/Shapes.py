import cv2
import numpy as np

# Detect_Shapes function detects rectangles, squares, circles, and triangles, 
# returning a tuple containing the lists of information for the shapes in the 
# order circle, rectangle, square, triangle

def detect_contours(frame):
    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blurred_gray_frame = cv2.GaussianBlur(gray_frame, (11,11), 0)
    _, threshold = cv2.threshold(blurred_gray_frame, 130, 255, cv2.THRESH_BINARY)
    
    contours, _ = cv2.findContours(
    threshold, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    
    return contours
    

def detect_and_draw_shapes(contours, frame):
    i = 0 
    for contour in contours: 
        if i == 0: 
            i += 1
            continue
        
        approximation =  cv2.approxPolyDP(
        contour, 0.01 * cv2.arcLength(contour, True), True)
        
        cv2.drawContours(frame, [contour], 0, (0, 0, 255), 5)
        
        M = cv2.moments(contour)
        if M['m00'] != 0.0:
            x = int(M['m10']/M['m00'])
            y = int(M['m01']/M['m00'])
            
        if len(approximation) == 3:
            cv2.putText(frame, 'Triangle', (x, y),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
    
        elif len(approximation) == 4:
            cv2.putText(frame, 'Quadrilateral', (x, y),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
    
        elif len(approximation) == 5:
            cv2.putText(frame, 'Pentagon', (x, y),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
    
        elif len(approximation) == 6:
            cv2.putText(frame, 'Hexagon', (x, y),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
    
        else:
            cv2.putText(frame, 'circle', (x, y),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            
    cv2.imshow("Shapes", frame)
    
frame_1 = cv2.imread("Frame_1.jpeg")
# frame_2 = cv2.imread("Frame_2.jpeg")
# frame_3 = cv2.imread("Frame_3.jpeg")
# frame_4 = cv2.imread("Frame_4.jpeg")

frame_1_contours = detect_contours(frame_1)
# frame_2_contours = detect_contours(frame_2)
# frame_3_contours = detect_contours(frame_3)
# frame_4_contours = detect_contours(frame_4)

detect_and_draw_shapes(frame_1_contours, frame_1)
# detect_and_draw_shapes(frame_2_contours, frame_2)
# detect_and_draw_shapes(frame_3_contours, frame_3)
# detect_and_draw_shapes(frame_4_contours, frame_4)

cv2.waitKey(0)
cv2.destroyAllWindows()