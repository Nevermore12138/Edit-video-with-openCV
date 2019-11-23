//
// Created by Zhipeng Xu on 2019/11/8.
//

#ifndef HANDLEVEDIO_VEDIOFUNC_H
#define HANDLEVEDIO_VEDIOFUNC_H
#include <string>

class videoProcessing
{
private:
    int frameH;
    int frameW;
    int fps;
    int numFrames;
public:
    videoProcessing();
    videoProcessing(int sldefH, int sldefW, int sldefNumFrame);
    void videoToImage(const std::string &readFileName);
    void imageTovideo(const std::string &saveFileName, int timeSec);
};
#endif //HANDLEVEDIO_VEDIOFUNC_H
