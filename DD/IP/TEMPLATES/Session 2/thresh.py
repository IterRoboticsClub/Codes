####################################
##PROJECT CELL
##IMAGE PROCESSING WORKSHOP
####################################
import cv2
import numpy as np

img = cv2.imread("Lion.jpg")

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

############################
#### THRESHOLD FUNCTION ####
############################
#ret, thresh = cv2.threshold(gray, 40, 255, cv2.THRESH_BINARY)

#cv2.imshow("Threshold", thresh)

cv2.imshow("GRAY", gray)

cv2.imshow("Original", img)

if cv2.waitKey(0) == 27:
    cv2.destroyAllWindows()
