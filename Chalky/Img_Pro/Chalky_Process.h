#include "../../Img_Process.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
using namespace std;

class Chalky_Process: public Img_Process
{
private:
	vector<cv::Mat> Result_C, Result_D, Result_B;	
	vector<cv::Mat> hist;				
	int count;			
    vector<vector<int>> Char_Parameter;				// Char_Parameter.at(i) has 4 parameters
													// store the sum of pixel's value in 4 intervals
public:
	vector<cv::Mat> Source_Img;
	
	vector<cv::Mat> readFile(const char *filename);

	Chalky_Process(const char *filename);
	vector<cv::Mat> cvImg();									// convert RGB to gray
	vector<cv::Mat> Denoising();								
	vector<cv::Mat> splitBack();								
	vector<cv::Mat> getHistogram();
	void drawHistogram(int pos);

	vector<vector<int>> calParameters();							// calculate the numver interesting intervals in hist
	int getCount();
};