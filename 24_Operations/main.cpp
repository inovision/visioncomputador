#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	//Nombre de la imagen que se va a cargar
	char NombreImagen1[] = "c://edx//LSI.jpg";
	char NombreImagen2[] = "c://edx//UC3M.jpg";
	Mat img1, img2;

	//Cargamos la imagen y se comprueba que lo ha hecho correctamente
	img1 = imread(NombreImagen1);
	img2 = imread(NombreImagen2);

	if (!img1.data || !img2.data) {
		cout << "Error al cargar las imagenes" << endl;
		exit(1);
	}
	imshow("Image1", img1);
	imshow("Image2", img2);
	
	Mat dst;
	
	add(img1, img2, dst, noArray(), -1);
	imshow("ADD", dst);
    subtract(img1, img2, dst, noArray(), -1);
    imshow("Subtract", dst);
    multiply(img1, img2, dst, (1.0), -1);
    imshow("Multiply", dst);
    divide(img1, img2, dst, (1.0), -1);
    imshow("Divide", dst);

	//Esperar a pulsar una tecla
	cvWaitKey(0);
	return 0;
}
