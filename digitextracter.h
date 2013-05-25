#ifndef DIGITEXTRACTER_H
#define DIGITEXTRACTER_H

#include "opencv2/imgproc/imgproc.hpp"
#include <list>

using namespace cv;
using namespace std;

class DigitExtracter
{
public:
    virtual list<float> extract(Mat &src, bool do_normalize) = 0;
    static const float minRat = 0.9;
    static const float maxRat = 1.1;
protected:
    struct ControlShape {
        Point top_left;
        Point top_right;
        Point bottom_left;
        Point bottom_right;
    };
    static bool sortArrayPointSize(vector<Point> a, vector<Point> b);
    static bool sortPointY(Point a, Point b);
    static double distance(Point a, Point b);
    static bool is_square(vector<Point>& contour, ControlShape &shape);
    static bool normalize(Mat &src, Mat &dst, ControlShape& shapea, ControlShape& shapeb, float avgW, float avgH);
    static void fill_shape(vector<Point>& corners, ControlShape& shape);
};

#endif // DIGITEXTRACTER_H
