#ifndef READER_H
#define READER_H
#include <opencv2/opencv.hpp>
#include <QString>

using namespace cv;
using namespace std;

class DigitReader {
public:
    DigitReader(QString path, int num_sample, int sample_size);
    float classify(Mat* imgSrc);
    int test();
    static Mat preprocessing(Mat* imgSrc, int new_width, int new_height);
    static Mat toBW(Mat* imgSrc);
private:
    static const int K = 10;
    QString file_path;
    int train_samples;
    int size;
    Mat* trainData;
    Mat* trainClasses;
    KNearest knn;
    bool getData();
    void train();
};

#endif // READER_H
