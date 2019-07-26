#ifndef CHALKY_PRO_H
#define CHALKY_PRO_H

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

class chalky_pro
{
private:
    cv::Mat Result_C, Result_D, Result_B;
    cv::Mat hist;
    vector<int> Char_Parameter;

public:
    cv::Mat Source_Img;
    void chalky_read(string file);
    cv::Mat cvImg();
    cv::Mat Denoising();
    cv::Mat splitBack();
    void getHistogram();
    cv::Mat drawHistogram();
    vector<int> calParameters();
    void chalky_clean();
};

#endif // CHALKY_PRO_H
