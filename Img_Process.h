#ifndef _IM_H
#define _IM_H

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
using namespace std;

class Img_Process
{
public:
	
	virtual vector<cv::Mat> readFile(const char *filename) = 0;		  // implement it in the base class
														              // read RGB image by filename

	virtual vector<cv::Mat> cvImg() = 0;						      // different implementation in 3 subclass
														              // convert RGB to binary, gary or HSL
														              // implement by calling cv::cvtColor(*)

	virtual vector<cv::Mat> Denoising() = 0;					      // using the biliteral filter
														              // call cv::biliteralFilter(*)

	virtual vector<cv::Mat> getHistogram() = 0;					       //	get histogram from the source image

	virtual vector<cv::Mat> splitBack() = 0;					      // background segmentation
														              // using the adaptive threshold

};

#endif