import cv2
import os

def read(filename):
	image = cv2.imread(filename, 0)
	return image

def resize(image, scale):
	width = image.shape[0]
	height = image.shape[1]
	image = cv2.resize(image, (int(height*scale), int(width*scale)))
	return image

files = os.listdir()
for i in files :
	if i[-5:] == ".jpeg":
		print (i)
		image = read(i)
		print ("Original Dimension : (" + str(image.shape[0]) + "," + str(image.shape[1]) + ")")
		print ("Resizing image to half its original size..")
		image = resize(image, 1/2)
		print ("New Dimension : (" + str(image.shape[0]) + "," + str(image.shape[1]) + ")")
		# cv2.imshow("resized" + i, image)
		# cv2.waitKey(0)
		cv2.imwrite("resized" + i, image)