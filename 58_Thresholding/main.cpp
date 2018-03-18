#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	//Nombre de la imagen que se va a cargar	
    Mat src, src_gray, dst, dst2, dst3, dst4;
	
	/// Load an image
	src = imread("c://edx//iCab_382x256.jpg", 1);

	/// Convert the image to Gray
	cvtColor(src, src_gray, CV_RGB2GRAY);

	/// Call the function to initialize
	threshold(src_gray, dst, 50, 255, THRESH_BINARY);
    threshold(src_gray, dst2, 50, 255, THRESH_BINARY_INV);
    threshold(src_gray, dst3, 150, 255, THRESH_TOZERO);
    threshold(src_gray, dst4, 150, 255, THRESH_TOZERO_INV);

	//Mostrar la imagen
	cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
	imshow("Original", src);
	cvNamedWindow("ThreShold", CV_WINDOW_AUTOSIZE);
	imshow("ThreShold", dst);
    cvNamedWindow("ThreSholdINV", CV_WINDOW_AUTOSIZE);
    imshow("ThreSholdINV", dst2);
    cvNamedWindow("ThreSholdtoZero", CV_WINDOW_AUTOSIZE);
    imshow("ThreSholdtoZero", dst3);
    cvNamedWindow("ThreSholdtoZeroINV", CV_WINDOW_AUTOSIZE);
    imshow("ThreSholdtoZeroINV", dst4);

	//Esperar a pulsar una tecla
	cvWaitKey(0);
	return 0;
}

