#include <iostream>
#include <string>
#include "vedioFunc.h"

using namespace std;


int main(int argc, char *argv[])
{
    string sourceFile("F:\\test\\111.avi");
    string savePath("F:\\test\\geneVideo.mp4");

//    videoProcessing videoHandle;
//    videoHandle.videoToImage(sourceFile);

    videoProcessing videoGene(768, 1366, 1960);
    videoGene.imageTovideo(savePath, 10);
    return 0;
}
