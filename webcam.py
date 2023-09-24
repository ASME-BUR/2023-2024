import cv2 
import numpy as np 
# Creates Video Capture for external webcam that I'm using, use 0 
# if you have an internal webcam 
import torch

model = torch.hub.load(\
                      'ultralytics/yolov5', \
                      'yolov5s', \
                      pretrained=True)

def score_frame(frame, model):
    device = 'cuda' if torch.cuda.is_available() else 'cpu'
    model.to(device)
    frame = np.array(torch.tensor(frame))
    results = model(frame)
    labels = results.xyxyn[0][:, -1].numpy()
    cord = results.xyxyn[0][:, :-1].numpy()
    return labels, cord

def plot_boxes(model, results, frame):
    labels, cord = results
    n = len(labels)
    x_shape, y_shape = frame.shape[1], frame.shape[0]
    for i in range(n):
        row = cord[i]
        # If score is less than 0.2 we avoid making a prediction.
        if row[4] < 0.2: 
            continue
        x1 = int(row[0]*x_shape)
        y1 = int(row[1]*y_shape)
        x2 = int(row[2]*x_shape)
        y2 = int(row[3]*y_shape)
        bgr = (0, 255, 0) # color of the box
        classes = model.names # Get the name of label index
        label_font = cv2.FONT_HERSHEY_SIMPLEX #Font for the label.
        cv2.rectangle(frame, \
                      (x1, y1), (x2, y2), \
                       bgr, 2) #Plot the boxes
        cv2.putText(frame,\
                    classes[labels[i]], \
                    (x1, y1), \
                    label_font, 0.9, bgr, 2) #Put a label over box.
        return frame

vid_capture = cv2.VideoCapture(1)


if(vid_capture.isOpened() == True):
    while(vid_capture.isOpened()):
        ret, frame = vid_capture.read()
        # hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
  
        # lower_red = np.array([30,150,50])
        # upper_red = np.array([255,255,180])
        # mask = cv2.inRange(hsv, lower_red, upper_red)
        # res = cv2.bitwise_and(frame,frame, mask= mask)
        if ret == True: 
            scores = score_frame(frame, model)
            frame = plot_boxes(model, scores, frame) # type: ignore
            cv2.imshow('Frane', frame)
            # cv2.imshow('mask',mask)
            # cv2.imshow('res',res)
            key = cv2.waitKey(20)
            if key == ord('q'):
                break
                
vid_capture.release()
cv2.destroyAllWindows()
exit(0)