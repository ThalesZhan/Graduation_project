#include <iostream>
#include <opencv2/opencv.hpp>
#include "chalky_pro.h"
using namespace std;

void chalky_pro::chalky_read(string file)
{
    Source_Img = cv::imread(file);
}

cv::Mat chalky_pro::cvImg()
{
    cv::cvtColor(Source_Img, Result_C, cv::COLOR_RGB2GRAY, 0);
    return Result_C;
}

cv::Mat chalky_pro::Denoising()
{
    cv::bilateralFilter(Result_C, Result_D, 10, 10, 10);
    return Result_D;
}

cv::Mat chalky_pro::splitBack()
{
    cv::threshold(Result_D, Result_B, 10, 255,
                  cv::THRESH_TOZERO);
    return Result_B;
}

void chalky_pro::getHistogram()
{
    int histSize[1], channels[1];
    float hranges[2];
    const float* ranges[1];
    channels[0] = 0;
    histSize[0] = 256;
    hranges[0] = 0.0;
    hranges[1] = 255.0;
    ranges[0] = hranges;

    cv::Point max_pt;
    double max_val;

    cv::calcHist(&Result_B, 1, channels,
                 cv::Mat(), hist,
                 1, histSize, ranges);

    cv::minMaxLoc(hist, NULL, &max_val, NULL, &max_pt);
    hist.at<float>(max_pt) = 0;
}

vector<int> chalky_pro::calParameters()
{
    cv::Scalar s;
    s = cv::sum(hist.rowRange(1, 25));
    Char_Parameter.push_back((int)s[0]);
    s = cv::sum(hist.rowRange(163, 187));
    Char_Parameter.push_back((int)s[0]);
    s = cv::sum(hist.rowRange(201, 225));
    Char_Parameter.push_back((int)s[0]);
    s = cv::sum(hist.rowRange(232, 256));
    Char_Parameter.push_back((int)s[0]);

    return Char_Parameter;
}

cv::Mat chalky_pro::drawHistogram()
{
    double max_val, min_val;
    cv::minMaxLoc(hist, &min_val, &max_val, NULL, NULL);

    cv::Mat histImg(256, 256, CV_8U, cv::Scalar(255));
    int hpt = (int)(0.9 * 256);

    for (int h = 0; h < 256; ++h)
    {
        float binVal = hist.at<float>(h);
        int intensity = (int)(binVal * hpt / max_val);

        cv::line(histImg, cv::Point(h, 256),
                 cv::Point(h, 256 - intensity), cv::Scalar::all(0));
    }

    return histImg;
}

void chalky_pro::chalky_clean()
{
    Char_Parameter.clear();
}
