import cv2 
import numpy as np 

vid_capture = cv2.VideoCapture(0)

if(vid_capture.isOpened() == True):
    while(vid_capture.isOpened()):
        ret, frame = vid_capture.read()
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        
        lower_red = np.array([30,150,50])
        upper_red = np.array([255,255,180])
        mask = cv2.inRange(hsv, lower_red, upper_red)
        res = cv2.bitwise_and(frame,frame, mask= mask)
        if ret == True: 
            cv2.imshow('Frame', frame)
            cv2.imshow('mask',mask)
            cv2.imshow('res',res)
            key = cv2.waitKey(20)
            if key == ord('q'):
                print(type(frame))
                print(frame.shapeqq)
                break
                
vid_capture.release()
cv2.destroyAllWindows()
exit(0)