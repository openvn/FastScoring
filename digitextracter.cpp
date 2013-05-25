#include "digitextracter.h"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <iostream>
#include <algorithm>

bool DigitExtracter::sortArrayPointSize(vector<Point> a, vector<Point> b) {
    return (a.size()>b.size());
}

bool DigitExtracter::sortPointY(Point a, Point b) {
    return (a.y < b.y);
}

void DigitExtracter::fill_shape(vector<Point>& corners, ControlShape& shape) {
    sort(corners.begin(), corners.end(), sortPointY);
    if(corners.at(0).x < corners.at(1).x) {
        shape.top_left = corners.at(0);
        shape.top_right = corners.at(1);
    } else {
        shape.top_left = corners.at(1);
        shape.top_right = corners.at(0);
    }
    if(corners.at(2).x < corners.at(3).x) {
        shape.bottom_left = corners.at(2);
        shape.bottom_right = corners.at(3);
    } else {
        shape.bottom_left = corners.at(3);
        shape.bottom_right = corners.at(2);
    }
}

bool DigitExtracter::normalize(Mat &src, Mat &dst, ControlShape &shapea, ControlShape &shapeb, float avgW, float avgH) {
    vector<Point2f> srcPoints(4);
    srcPoints[0] = shapea.bottom_left;
    srcPoints[1] = shapea.bottom_right;
    srcPoints[2] = shapeb.top_right;
    srcPoints[3] = shapeb.top_left;

    vector<Point2f> dstPoints(4);
    dstPoints[0] = shapea.bottom_left;
    dstPoints[1] = Point2f(shapea.bottom_left.x + avgW, shapea.bottom_left.y);
    dstPoints[2] = Point2f(shapea.bottom_left.x + avgW, shapea.bottom_left.y + avgH);
    dstPoints[3] = Point2f(shapea.bottom_left.x, shapea.bottom_left.y + avgH);
    warpPerspective(src, dst, findHomography(srcPoints, dstPoints), src.size());
    return false;
}

double DigitExtracter::distance(Point a, Point b) {
    double i = a.x - b.x;
    double t = a.y - b.y;
    return sqrt(i*i + t*t);
}

bool DigitExtracter::is_square(vector<Point> &contour, ControlShape &shape) {
    vector<Point> approx;
    approxPolyDP(contour, approx, arcLength(contour, true)*0.02, true);
    if(approx.size() == 4) {
        fill_shape(approx, shape);
        return true;
    }
    return false;
}

