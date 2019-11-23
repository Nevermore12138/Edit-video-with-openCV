import cv2
import os


fps = 100 
size = (640, 480) 
videowriter = cv2.VideoWriter("a.mp4",cv2.VideoWriter_fourcc('m','p','4','v'),fps,size)
video_path = '/home/z/Desktop/Untitled Folder/2_plus_2'

frame_paths = sorted([os.path.join(video_path, fn) for fn in next(os.walk(video_path))[2]])

num_frames = len(frame_paths)

for i in range(num_frames):

	frame_name = frame_paths[i]

	img = cv2.imread(frame_name)
	videowriter.write(img)

videowriter.release()
