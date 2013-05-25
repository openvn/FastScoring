#include "pointdigitextracter.h"
#include <opencv2/opencv.hpp>
#include <iostream>

PointDigitExtracter::PointDigitExtracter()
{
}

list<float> PointDigitExtracter::extract(Mat &src, bool do_normalize) {
    //find all contours
    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    threshold(src, src, 140, 255, THRESH_BINARY);
    Canny(src, canny_output, 100, 100*2, 5);
    findContours(canny_output, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, Point(0, 0));
    //sort contours base n len
    sort(contours.begin(), contours.end(),sortArrayPointSize);

    //find the mainbox and two equilateral triangle
    Rect box1, box2;
    ControlShape s1, s2;
    int found = 0;
    for(uint i = 1; i< contours.size(); i++) {
        vector<Point> icontor = contours.at(i);
        Rect r = boundingRect(icontor);
        float ratio = r.width/r.height;
        if(minRat <= ratio && ratio <= maxRat) {
            //the right box must not so tall or long
            ControlShape shape;
            if(is_square(icontor, shape)) {
                if(found == 0) {
                    box1 = r;
                    s1 = shape;
                } else if(found == 1) {
                    box2 = r;
                    s2 = shape;
                    break;
                }
                found++;
            }
        }
    }
    float avgW = (distance(s1.top_left, s1.top_right) + distance(s1.bottom_left, s1.bottom_right)
            + distance(s1.top_left, s1.bottom_left) + distance(s1.top_right, s1.bottom_right)
            + distance(s2.top_left, s2.top_right) + distance(s2.bottom_left, s2.bottom_right)
            + distance(s2.top_left, s2.bottom_left) + distance(s2.top_right, s2.bottom_right))/8;

    float startY, startX, square_size;
    Mat src_c = src.clone();
    if(do_normalize) {
        if(s1.top_left.y < s2.top_left.y) {
            float totalH = (distance(s1.bottom_left, s2.top_left) + distance(s1.bottom_right, s2.top_right))/2;
            square_size = (((totalH-avgW*29/60)/(26+(2/3)))+avgW)/2;

            startY = s1.bottom_left.y + square_size*21/60 + square_size;
            startX = s1.bottom_left.x;
            normalize(src, src, s1, s2, square_size, totalH);
        } else {
            float totalH = (distance(s2.bottom_left, s1.top_left) + distance(s2.bottom_right, s1.top_right))/2;
            square_size = (((totalH-avgW*29/60)/(26+(2/3)))+avgW)/2;

            startY = s2.bottom_left.y + square_size*21/60 + square_size;
            startX = s2.bottom_left.x;
            normalize(src, src, s2, s1, square_size, totalH);
        }
    }
    circle(src, s2.bottom_left, 5, Scalar(124));
    circle(src, Point(s2.bottom_left.x, s2.bottom_left.y + avgW/3), 5, Scalar(124));

    for(int i = 0; i < 25; i++) {
        rectangle(src, Rect(startX, startY, square_size, square_size), Scalar(150));
        rectangle(src_c, Rect(startX, startY, square_size, square_size), Scalar(150));
        startY = floor(startY + square_size);
    }
    imwrite("/home/nvcnvn/Desktop/testSrc.png", src_c);
    imwrite("/home/nvcnvn/Desktop/testWrap.png", src);
    list<float> results;
    return results;
}
