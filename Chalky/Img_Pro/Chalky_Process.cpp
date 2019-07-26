#include "Chalky_Process.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
using namespace std;

vector<cv::Mat> Chalky_Process::readFile(const char *filename)
{
    string str = filename;
    str = "./Pre_Process/yml/" + str;
    cv::FileStorage fs2(str, cv::FileStorage::READ);

    vector<cv::Mat> imgs;
    cv::Mat img;
    int num = 1;
    int count_sum;

    fs2["count"] >> count_sum;

    for ( ; num <= count_sum; num++)
    {
        str = "Mat" + to_string(num);
        fs2[str] >> img;
        imgs.push_back(img.clone());
    }

    return imgs;
}

Chalky_Process::Chalky_Process(const char* filename)
{
	Source_Img = readFile(filename);
	count = Source_Img.size();
}

vector<cv::Mat> Chalky_Process::cvImg()
{
	cv::Mat img;
	for (int i = 0; i < count; ++i)
    {
        cv::cvtColor(Source_Img.at(i), img, cv::COLOR_RGB2GRAY, 0);			// convert RGB to GRAY
        Result_C.push_back(img.clone());
    }

    return Result_C;
}

vector<cv::Mat> Chalky_Process::Denoising()
{
	cv::Mat img;
	for (int i = 0; i < count; ++i)
    {
        cv::bilateralFilter(Result_C.at(i), img, 10, 10, 10);				// bilateral denoising
        Result_D.push_back(img.clone());
    }

    return Result_D;
}

vector<cv::Mat> Chalky_Process::splitBack()
{
	cv::Mat img;
	for (int i = 0; i < count; ++i)
	{
		cv::threshold(Result_D.at(i), img, 10, 255,
                      cv::THRESH_TOZERO);
		Result_B.push_back(img.clone());						
	}

	return Result_B;        	
}

vector<cv::Mat> Chalky_Process::getHistogram()
{
    cv::Mat img;
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

    for (int i = 0 ; i < count; ++i)
    {
        cv::calcHist(&Result_B.at(i), 1, channels,
                     cv::Mat(), img,
                     1, histSize, ranges);

        cv::minMaxLoc(img, NULL, &max_val, NULL, &max_pt);              // filter the background
        img.at<float>(max_pt) = 0;

        hist.push_back(img.clone());
    }

    return hist;
}

void Chalky_Process::drawHistogram(int pos)
{
    cv::Mat img = hist.at(pos);
    double max_val, min_val;
    cv::minMaxLoc(img, &min_val, &max_val, NULL, NULL);

    cv::Mat histImg(256, 256, CV_8U, cv::Scalar(255));
    int hpt = (int)(0.9 * 256);

    for (int h = 0; h < 256; ++h)
    {
        float binVal = img.at<float>(h);
        int intensity = (int)(binVal * hpt / max_val);

        cv::line(histImg, cv::Point(h, 256), 
                 cv::Point(h, 256 - intensity), cv::Scalar::all(0));
    }

    cv::namedWindow("Histogram", 0);
    cv::imshow("Histogram", histImg);
}

vector<vector<int>> Chalky_Process::calParameters()
{
    cv::Mat m;
    int cur_par[4];
    cv::Scalar s;
    for (int i = 0; i < count; ++i)
    {
        m = hist.at(i);
        s = cv::sum(m.rowRange(1, 25));
        cur_par[0] = (int) s[0];
        s = cv::sum(m.rowRange(163, 187));
        cur_par[1] = (int) s[0];
        s = cv::sum(m.rowRange(201, 225));
        cur_par[2] = (int) s[0];
        s = cv::sum(m.rowRange(232, 256));
        cur_par[3] = (int) s[0];

        vector<int> v(cur_par, cur_par + 4);
        Char_Parameter.push_back(v);
    }
    return Char_Parameter;
}

int Chalky_Process::getCount()
{
    return count;
}