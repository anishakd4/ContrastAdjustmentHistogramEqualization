import cv2
import numpy as np

#read image
image = cv2.imread("../assets/putin.jpg")

#convert to YCrCb color space
imageYcb = cv2.cvtColor(image, cv2.COLOR_BGR2YCrCb)

#split into channels
Y, C, B = cv2.split(imageYcb)

#histogram equalization
Y = cv2.equalizeHist(Y)

#merge the channels
imageYcb = cv2.merge([Y, C, B])

#convert back to BGR color space
result = cv2.cvtColor(imageYcb, cv2.COLOR_YCrCb2BGR)

#create windows to display image
cv2.namedWindow("image", cv2.WINDOW_NORMAL)
cv2.namedWindow("result", cv2.WINDOW_NORMAL)

#display images
cv2.imshow("image", image)
cv2.imshow("result", result)

#press Esc to exit the program
cv2.waitKey(0)

#close all the opended windows
cv2.destroyAllWindows()