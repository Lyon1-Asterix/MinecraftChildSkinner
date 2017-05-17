#include "utils.hpp"



/**
 * Learn the background from @cap
 * and train the statistical backgroundSubtractor @mog.
 *
 */
void backgroundLearning(VideoCapture& cap, Ptr<BackgroundSubtractor>& mog, int nbFrame)
{

    Mat frame;
    Mat mogFrame;

    std::cout << "Apprentissage du fond, ne passez pas devant !" << std::endl;
    for(int i = 0; i < nbFrame; ++i)
    {

        bool bSuccess = cap.read(frame);
        if (!bSuccess)
        {
            std::cout << "Cannot read the frame from video file" << std::endl;
            break;
        }

        mog->apply(frame, mogFrame);
    }

    std::cout << "Fond appris, vous pouvez y aller !" << std::endl;
}


/**
* Extract the moving element of the @frame (colored picture)
* and generate a Threshold (in @mogThreshold) with only the moving element
* @mog trained statistical backgroundSubtractor
*/
void backgroundSubtractor(Mat& frame, Mat& mogThreshold, Ptr<BackgroundSubtractor>& mog)
{

    mog->apply(frame, mogThreshold, 0);

    erode(mogThreshold, mogThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    dilate(mogThreshold, mogThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

    dilate(mogThreshold, mogThreshold, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)));
    erode(mogThreshold, mogThreshold, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)));
}