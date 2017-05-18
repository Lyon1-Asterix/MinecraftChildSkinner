#include <iostream>
#include "opencv2/core/core.hpp"
//#include "opencv2/bgsegm.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <string>
#include <sstream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{

    VideoCapture vcap(1);

    if(!vcap.isOpened())
    {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    int frame_width=   vcap.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height=   vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
    VideoWriter video("../Data/out.avi",CV_FOURCC('M','J','P','G'),vcap.get(CV_CAP_PROP_FPS), Size(frame_width,frame_height),true);

    std::cout << "Enregistrement du fond" << std::endl;

    Mat frame;
    for(int i = 0; i < 60; ++i)
    {
        std::cout << "Licorne" << std::endl;
    }
    
    for(int i = 0; i < 300; ++i)
    {

        vcap >> frame;
        video.write(frame);
    }

    video.release();
    vcap.release();

    return EXIT_SUCCESS;
}
