####################################
##PROJECT CELL
##IMAGE PROCESSING WORKSHOP
####################################
import cv2
import numpy as np

img = cv2.imread("Mask_Img1.png")

###########################
####specify the ranges ####
###########################
#param1 = [36, 28, 237]
#param2 = [40, 30, 240]
#lower = np.array([36, 28, 237])
#upper = np.array([40, 30, 240])

#################
#### masking ####
#################
#mask = cv2.inRange(img, lower, upper)

#####################################################
####bitwise and for retaining the original color ####
#####################################################
#res = cv2.bitwise_and(img, img,mask= mask)

#cv2.imshow("bitwise_and", res)

#cv2.imshow("mask", mask)

cv2.imshow("Original", img)

if cv2.waitKey(0) == 27:
    cv2.destroyAllWindows()
