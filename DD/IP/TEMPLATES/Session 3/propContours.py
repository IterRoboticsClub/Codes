
############################################
## PROJECT CELL
## Image Processing Workshop
############################################
## Import OpenCV
import numpy
import cv2
############################################

## Read the image
img = cv2.imread('map.png')

## Do the processing
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(gray,170,255,0)

##find the contours
contours,hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

##select any contour
#i = 

##find the co-ordinates of centroid of the contour
#M = cv2.moments(contours[i]) 
#cx = int(M['m10']/M['m00'])
#cy = int(M['m01']/M['m00'])

##find the area of the contour
    
cv2.drawContours(img,contours,i,(0,0,255),3)
cv2.imshow('contours',img)



############################################

############################################
## Close and exit
cv2.waitKey(0)
cv2.destroyAllWindows()
############################################
