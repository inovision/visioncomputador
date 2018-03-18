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

    char NomImagen[] = "c://edx//1.jpg";

    Mat image, dst;
    image = imread(NomImagen, 1);

    if (!image.data){
        cout << "Error al cargar imagen" << endl;
        exit(1);
    }

    vector<Mat> bgr_planes;
    split(image, bgr_planes);

    int histSize = 256;

    float range[] = {0, 256};
    const float* histRange = {range};

    bool uniform = true;
    bool accumulate = false;

    Mat b_hist, g_hist, r_hist;

    calcHist(&bgr_planes[0],1,0,Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[1],1,0,Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[2],1,0,Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double)hist_w/histSize);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));

    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for (int i =1; i <histSize; i++){
        line(histImage, Point(bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1))), Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255,0,0), 2, 8, 0);
        line(histImage, Point(bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1))), Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0,255,0), 2, 8, 0);
        line(histImage, Point(bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1))), Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0,0,255), 2, 8, 0);
    }

    namedWindow("Original");
    imshow("Original", image);
    namedWindow("Histograma");
    imshow("Histograma", histImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
