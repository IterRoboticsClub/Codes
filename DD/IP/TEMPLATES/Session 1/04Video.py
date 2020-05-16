#######################################
##Project Cell
##Image Processing Workshop
#######################################
##import opencv
import cv2
#######################################

##Initialize the camera
cap = cv2.VideoCapture(0)

##loop
    ret, img = cap.read()
    cv2.imshow('video',img)
    ##break
    
       
cap.release()
cv2.destroyAllWindows()




    
    

