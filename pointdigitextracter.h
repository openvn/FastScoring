#ifndef POINTDIGITEXTRACTER_H
#define POINTDIGITEXTRACTER_H

#include "digitextracter.h"
class PointDigitExtracter : public DigitExtracter
{
public:
    PointDigitExtracter();
    list<float> extract(Mat &src, bool do_normalize);
};

#endif // POINTDIGITEXTRACTER_H
