#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    char NomImagen[] = "c://gray.jpg";

    Mat image, imageResult;
    image = imread(NomImagen, 1);

    if (!image.data){
        cout << "Error al cargar imagen" << endl;
        exit(1);
    }

    Mat lut(1,256,CV_8U);

    for (int i = 0; i < 256; i++){
        //lut.at<uchar>(i) = 255 - i; //inversa
        //lut.at<uchar>(i) = pow((float)i * 255, (float)(1/2.0)); // raiz cuadrada
        lut.at<uchar>(i) = pow((float)i, (float)(3.0)) / (255 * 255); // cubica
    }
    LUT(image, lut, imageResult);


    namedWindow("Original");
    imshow("Original", image);
    namedWindow("LUT");
    imshow("LUT", imageResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}
