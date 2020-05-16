
############################################
## PROJECT CELL
## Image Processing Workshop
############################################
## Import OpenCV
import numpy
import cv2
############################################

####Read the image
img = cv2.imread('map.png')

####Do the processing
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(gray,170,255,0)

####Find the contours
#contours,hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

####draw the contours
cv2.drawContours()
cv2.imshow('contours',img)

## Close and exit
cv2.waitKey(0)
cv2.destroyAllWindows()
############################################
