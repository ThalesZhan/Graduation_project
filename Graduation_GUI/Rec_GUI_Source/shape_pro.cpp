#include <iostream>
#include <opencv2/opencv.hpp>
#include "shape_pro.h"
using namespace std;

void shape_pro::shape_read(string file)
{
    Source_Img = cv::imread(file);
}

cv::Mat shape_pro::cvImg()
{
    cv::cvtColor(Source_Img, Result_C, cv::COLOR_RGB2GRAY, 0);
    return Result_C;
}

cv::Mat shape_pro::Denoising()
{
    cv::bilateralFilter(Result_C, Result_D, 10, 10, 10);
    return Result_D;
}

cv::Mat shape_pro::splitBack()
{
    cv::adaptiveThreshold(Result_D, Result_B, 255,
                                  cv::ADAPTIVE_THRESH_GAUSSIAN_C,
                                  cv::THRESH_BINARY,121, 0);
    return Result_B;
}

vector<int> shape_pro::calParameters()
{
    int row = Result_B.rows;
    int col = Result_B.cols;
    int width = 0, height = 0;
    vector<int> temp;

    for (int k = 0; k < row; ++k)
    {
        for (int j = 0; j < col; ++j)
        {
            if (Result_B.at<uchar>(k, j) != 0)
                temp.push_back(j);
        }
        if (temp.size() > 1)
        {
            int tp_width = temp.at(temp.size() - 1) - temp.at(0);
            if (tp_width > width)
                width = tp_width;
        }
        temp.clear();
    }

    for (int k = 0; k < col; ++k)
    {
        for (int j = 0; j < row; ++j)
        {
            if (Result_B.at<uchar>(j, k) != 0)
                temp.push_back(j);
        }
        if (temp.size() > 1)
        {
            int tp_height = temp.at(temp.size() - 1) - temp.at(0);
            if (tp_height > height)
                height = tp_height;
        }
        temp.clear();
    }

    Char_Parameter.push_back(width);
    Char_Parameter.push_back(height);

    return Char_Parameter;
}

void shape_pro::shape_clean()
{
    Char_Parameter.clear();
}
