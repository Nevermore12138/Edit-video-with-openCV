//
// Created by Zhipeng Xu on 2019/11/8.
//
#include "vedioFunc.h"
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

videoProcessing::videoProcessing():frameH(1), frameW(1), fps(1), numFrames(1){}

videoProcessing::videoProcessing(int sldefH, int sldefW, int sldefNumFrame)
{
    frameH = sldefH;
    frameW = sldefW;
    numFrames = sldefNumFrame;

}

void videoProcessing::videoToImage(const std::string &readFileName)
{
    VideoCapture myCapture;
    myCapture.open(readFileName.c_str());
    Mat frame;
    if (!myCapture.isOpened())
    {
        cerr << "cvCaptureFromVideo failed!!" << endl;
    }

//    namedWindow("output", CV_WINDOW_AUTOSIZE);
    frameH = myCapture.get(CV_CAP_PROP_FRAME_HEIGHT);
    frameW = myCapture.get(CV_CAP_PROP_FRAME_WIDTH);
    fps = myCapture.get(CV_CAP_PROP_FPS);
    numFrames = myCapture.get(CV_CAP_PROP_FRAME_COUNT);
    cout<<"Height: "<<frameH<<"; Width: "<<frameW<<"; FPS: "<<fps<<"; Frame nums:"<<numFrames<<endl;

    int i = 0;
    char image_name[50];

    while(myCapture.read(frame))
    {
//        imshow("output", frame);
//        waitKey(10);
        sprintf(image_name, "F:/ImageHandle/VideoToImage/%s%05d%s", "image", ++i, ".png");
        cout<<image_name<<endl;
        imwrite(image_name, frame);
        if(i == numFrames+1)
            break;
    }
//    cvDestroyWindow("output");
}

void videoProcessing::imageTovideo(const std::string &saveFileName, int timeSec)
{
    VideoWriter myWriter;
    fps = (int)(numFrames/timeSec);
    Size size = Size(frameW, frameH);
    myWriter.open(saveFileName, CV_FOURCC('m','p','4','v'), fps, size, true);
    Mat readFrame;
    int i = 0;
    char readFileName[50];
    while(i<=numFrames)
    {
        sprintf(readFileName, "F:/ImageHandle/VideoToImage/%s%05d%s", "image", ++i, ".png");
        readFrame=imread(readFileName);
        myWriter.write(readFrame);
        cout<<i<<endl;
    }
    myWriter.release();
}
