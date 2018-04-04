#include <iostream>
#include <opencv/cv.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


//*******************************************************************************************************
// Transformada de Hough
//*******************************************************************************************************

int main(int argc, char** argv)
{
    //Nombre de la imagen que se va a cargar
    Mat src, dst, dst2;
    //Cargamos la imagen y se comprueba que lo ha hecho correctamente
    src = imread("c://edx//LetrasI_BW.jpg", 1);
    if (!src.data) {
        cout<< "Error al cargar la imagen: " << "LetrasI.jpg" <<endl;
        exit(1);
    }

    //dilate(src, dst, Mat(), Point(-1, -1), 1);
    //erode(dst, dst2, Mat(), Point(-1, -1), 1);
    morphologyEx(src,dst,CV_MOP_OPEN, Mat(), Point(-1,-1), 1);
    morphologyEx(src,dst2,CV_MOP_CLOSE, Mat(), Point(-1,-1), 1);


    //Mostrar la imagen
    namedWindow("Original", CV_WINDOW_AUTOSIZE);
    imshow("Original", src );

    namedWindow("Morphology", CV_WINDOW_AUTOSIZE);
    imshow("Morphology", dst);

    namedWindow("Morphology2", CV_WINDOW_AUTOSIZE);
    imshow("Morphology2", dst2);


    //Esperar a pulsar una tecla
    waitKey(0);
    return 0;
}

