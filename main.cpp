#include "mainwindow.h"
#include "digitreader.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <digitreader.h>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
