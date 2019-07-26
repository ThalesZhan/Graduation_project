#include "Shape_Process.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
using namespace std;

vector<cv::Mat> Shape_Process::readFile(const char *filename)
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

Shape_Process::Shape_Process(const char* filename)
{ 
	Source_Img = readFile(filename);
	count = Source_Img.size();
}

vector<cv::Mat> Shape_Process::cvImg()
{
	cv::Mat img;
	for (int i = 0; i < count; ++i)
    {
        cv::cvtColor(Source_Img.at(i), img, cv::COLOR_RGB2GRAY, 0);			// convert RGB to GRAY
        Result_C.push_back(img.clone());
    }

    return Result_C;
}

vector<cv::Mat> Shape_Process::Denoising()
{
	cv::Mat img;
	for (int i = 0; i < count; ++i)
    {
        cv::bilateralFilter(Result_C.at(i), img, 10, 10, 10);				// bilateral denoising
        Result_D.push_back(img.clone());
    }

    return Result_D;
}



vector<cv::Mat> Shape_Process::splitBack()
{
	cv::Mat img;
	for (int i = 0; i < count; ++i)
	{
		cv::adaptiveThreshold(Result_D.at(i), img, 255, 					// binary image
                              cv::ADAPTIVE_THRESH_GAUSSIAN_C,
                              cv::THRESH_BINARY,121, 0);
		Result_B.push_back(img.clone());						
	}

	return Result_B;        	
}

vector<cv::Mat> Shape_Process::getHistogram()											// image processing of shape need not histogram
{ }


vector<vector<int>> Shape_Process::calParameters()
{
	int cur_para[4];

	// square
	cv::Scalar s;											

	// perimeter
	cv::Mat img;											
	cv::Scalar ss;

	// axes
	int x0, y0, row, col;
	cv::Mat center = (cv::Mat_<int>(1, 2) << 0, 0);
	cv::Mat img1, img2;

	cv::Mat pt = (cv::Mat_<int>(1, 2) << 0, 0);				// curren point of searching
	double dis_cur, dis_max, dis_min;

	for (int i = 0; i < count; ++i)
	{
		// area
        s = cv::sum(Result_B.at(i));
        cur_para[0] = (int) s[0] / 255;

        // perimeter
        cv::Canny(Result_B.at(i), img, 0, 255);
        ss = cv::sum(img);
        cur_para[1] = (int) ss[0] / 255;
  

		//axes
		img1 = Result_B.at(i);
		cv::Canny(img1, img2, 0, 255);
		row = img1.rows;
		col = img1.cols;



		// 	find the centroid
		x0 = 0, y0 = 0;
		dis_max = 0, dis_min = 64;
		for (int k = 0; k < row; ++k)
		{
			for (int j = 0; j < col; ++j)
			{
				if (img1.at<uchar>(k, j) != 0 )
				{
					x0 = x0 + k;
					y0 = y0 + j;
				}
			}
		}
		center.at<int>(0, 0) = x0 / cur_para[0];
		center.at<int>(0, 1) = y0 / cur_para[0];

		// search the major and minor axes
		for (int k = 0; k < row; ++k)
		{
			for (int j = 0; j < col; ++j)
			{
				if (img2.at<uchar>(k, j) != 0 )
				{
					pt.at<int>(0, 0) = k;						
					pt.at<int>(0, 1) = j;
					dis_cur = cv::norm(center, pt, cv::NORM_L2);

					if (dis_cur > dis_max)
						dis_max = dis_cur;

					if (dis_cur < dis_min)
						dis_min = dis_cur;
				}
			}
		}	
		cur_para[2] = (int) 2 * dis_max;
		cur_para[3] = (int) 2 * dis_min;

		//find width and height
		int width = 0, height = 0, tp_sz;
		vector<int> temp;

		for (int k = 0; k < row; ++k)
		{
			for (int j = 0; j < col; ++j)
			{
				if (img2.at<uchar>(k, j) != 0)
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
				if (img2.at<uchar>(j, k) != 0)
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

		cur_para[4] = width;
		cur_para[5] = height;

		vector<int> v(cur_para, cur_para + 6);

		Char_Parameter.push_back(v);
	}

	return Char_Parameter;
}

int Shape_Process::getCount()
{
	return count;
}