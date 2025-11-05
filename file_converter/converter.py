import cv2
from matplotlib.image import imread

image_path = "/home/guenael/Downloads/image.jpeg"

image = cv2.imread(image_path)

gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

cv2.imwrite("/home/guenael/Downloads/gray_image.png", gray_image)

image = imread("/home/guenael/Downloads/gray_image.png")

print(image)
