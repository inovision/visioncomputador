#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video/background_segm.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat frame, back, fore, dest;
    cv::VideoCapture cap("c://edx//IcabMovimientoEscenaEstatica.mp4");
    Ptr<BackgroundSubtractorMOG2> bg = createBackgroundSubtractorMOG2(500, 16, true);

	cv::namedWindow("Frame");
	cv::namedWindow("Background");
	cv::namedWindow("Foreground");

	for (;;)
	{
		cap >> frame;
		if (!frame.data)
		{
			cout << "Error al cargar el frame.\n";
			exit(1);
		}

		bg->setNMixtures(5);
		bg->apply(frame, fore);
		bg->getBackgroundImage(back);

		erode(fore, fore, Mat());
		dilate(fore, fore, Mat());
		cvtColor(fore, fore, CV_GRAY2BGR);
		bitwise_and(frame, fore, dest);

		imshow("Frame", frame);
		imshow("Background", back);
		imshow("Foreground", dest);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}

