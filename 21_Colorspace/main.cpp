#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    char NomImagen[] = "c://color.jpg";

    Mat image, imHSV;

    image = imread(NomImagen, 1);

    if (!image.data){
        cout << "Error al cargar imagen" << endl;
        exit(1);
    }

    vector<Mat> bgr_planes;
    split(image, bgr_planes);

    cvtColor(image, imHSV, CV_BGR2HSV);
    vector<Mat> hsv_planes;
    split(imHSV, hsv_planes);




    namedWindow("Original");
    imshow("Original", image);
    namedWindow("HSV");
    imshow("HSV", imHSV);
    namedWindow("H");
    imshow("H", hsv_planes[0]);
    namedWindow("HSV");
    imshow("S", hsv_planes[1]);
    namedWindow("HSV");
    imshow("V", hsv_planes[2]);



    cvWaitKey(0);
    return 1;
}
