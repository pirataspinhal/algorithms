import numpy as np
import cv2
import math


def padding(image,padd):
	psize=math.floor(padd/2)
	row,col = image.shape
	nimg=np.zeros((row+2*psize,col+2*psize))
	for i in range(row):
		for j in range(col):
			nimg[i+psize][j+psize]=image[i][j]
	return nimg

def removepadd(image, ker):
	row,col=image.shape
	pad=int(math.floor(ker/2))
	newimg=np.zeros((row-2*pad,col-2*pad))
	for i in range(row-2*pad):
		for j in range(col-2*pad):
			newimg[i][j]=image[i+pad][j+pad]
	return newimg

def avgfil(ker):
	a=np.ones((ker,ker))/(ker*ker)	
	return a

def unsharp(ker):
	avg=avgfil(ker)*-1
	impulse=np.zeros((ker,ker))
	impulse[int((ker+1)/2)][int((ker+1)/2)]=2
	return impulse+avg


def applyfil(img,matfil,ker,r,c):
	a=r-math.floor(ker/2)
	b=c-math.floor(ker/2)
	sum=0.0
	for x in range(ker):
		for y in range(ker):
			sum = sum + (img[a+x][b+y]*matfil[x][y])
	return sum


def filter(img,ker,case):
	row,col=img.shape
	pad=math.floor(ker/2)
	newimg = np.zeros((row,col))
	matfil=None
	if(case==0):
		matfil=avgfil(ker)
	elif(case==1):
		matfil=unsharp(ker)
	for i in range(row-2*pad):
		for j in range(col-2*pad):
			newimg[pad+i][pad+j]=applyfil(img,matfil,ker,pad+i,pad+j)
	return newimg

def absolute(img):
	row,col=np.shape(img)
	for i in range(row):
		for j in range(col):
			if(img[i][j]>255):
				img[i][j]=255
			else:
				img[i][j]=abs(img[i][j])
	return img

img1=cv2.imread('./Chandrayaan2 - Q3a-inputimage.png',0) #add the image
img=padding(img1,7)
img=filter(img,7,0)
img=removepadd(img,7)
img=img.astype(np.uint8)
cv2.imwrite("Average.png",img)

mask=img1.astype(int)-img.astype(int)
nimg=absolute(img1.astype(int)+mask)
cv2.imwrite("Sharpened.png",nimg.astype(np.uint8))

img=padding(img1,7)
img=filter(img,7,1)
img=removepadd(img,7)
img=absolute(img)
img=img.astype(np.uint8)
cv2.imwrite("Unsharp.png",img)


