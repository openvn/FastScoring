#include "mainwindow.h"
#include "digitreader.h"
#include "digitextracter.h"
#include "pointdigitextracter.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <digitreader.h>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
//    Mat test = imread("/home/nvcnvn/WorkSpace/Products/asd/data/pencil/9/31.pbm", CV_LOAD_IMAGE_GRAYSCALE);
//    DigitReader d("/home/nvcnvn/WorkSpace/Products/asd/data/pencil", 50, 50);
//    cout << d.classify(test) << endl << d.test();
    Mat src = imread("/home/nvcnvn/Desktop/scanned/form/point/Scanned3.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    DigitExtracter* d = new PointDigitExtracter();
    d->extract(src, true);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
