#ifndef SHAPE_PRO_H
#define SHAPE_PRO_H

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

class shape_pro
{
private:
    cv::Mat Result_C, Result_D, Result_B;
    vector<int> Char_Parameter;

public:
    cv::Mat Source_Img;

    void shape_read(string file);
    cv::Mat cvImg();
    cv::Mat Denoising();
    cv::Mat splitBack();
    vector<int> calParameters();
    void shape_clean();
};

#endif // SHAPE_PRO_H
