import cv2

video = cv2.VideoCapture('/home/z/Desktop/Untitled Folder/123.mp4')

count = 0

success = video.isOpened()
while success:
	success, image = video.read()

	if success:
		cv2.imwrite('/home/z/Desktop/Untitled Folder/123/'+str(count).zfill(5)+'.png', image)
	count += 1










