#include "mainwindow.h"
#include "digitreader.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <digitreader.h>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
    Mat test = imread("609.pbm", CV_LOAD_IMAGE_GRAYSCALE);
    DigitReader d("/home/nvcnvn/WorkSpace/test/basicOCR/OCR/", 50, 40);
    cout << d.classify(&test);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
