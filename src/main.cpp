#include "utils.hpp"


int main(int argc, char ** argv)
{
    VideoCapture backgroundCap("Data/out.avi");

    if ( !backgroundCap.isOpened())
    {
        std::cout << "Cannot open the video file" << std::endl;
        return EXIT_FAILURE;
    }

    Mat frame;
    Mat frameWithoudFoground;
    Mat mogThreshold;


    Ptr<BackgroundSubtractor> mog = bgsegm::createBackgroundSubtractorMOG();

    backgroundLearning(backgroundCap, mog, 300);

    VideCapture cameraCap(1);

    double fps = cameraCap.get(CV_CAP_PROP_FPS);
    int wait = 1000 / fps;

    if ( !backgroundCap.isOpened())
    {
        std::cout << "Cannot open the video file" << std::endl;
        return EXIT_FAILURE;
    }

    while(true)
    {
        bool bSuccess = cap.read(frame);

        if (!bSuccess)
        {
            std::cout << "Cannot read the frame from video file" << std::endl;
            break;
        }

        backgroundSubtractor(frame, mogThreshold, mog);

        frame.copyTo(frameWithoudFoground, mogThreshold);

        imshow("frameWithoudFoground", frameWithoudFoground);

        if(waitKey(wait) == 27)
        {
            break;
        }
    }
}