#include "../../Img_Process.h"

class Shape_Process: public Img_Process
{
private:
	vector<cv::Mat> Result_C, Result_D, Result_B;		// store the result image
	vector<vector<int>> Char_Parameter;					// Char_Parameter.at(i) has 4 parameters
														// A:area, P:perimeter, Major_axis, Minor_axis
	int count;											// the count of samples

public:

	vector<cv::Mat> Source_Img;
	vector<cv::Mat> readFile(const char *filename);

	Shape_Process(const char* filename);									// Source_Img = readFile(filename)
	vector<cv::Mat> cvImg();							// convert RGB to binary, store in Result_C
	vector<cv::Mat> Denoising();						// using the bilitera filter, Result_D
	vector<cv::Mat> splitBack();						// using adaptive threshold, Result_B
	vector<cv::Mat> getHistogram();

// calculate the square by calling cv::sum()
// store in Char_Parameter.at(i).at(0)
// calculate the perimeter by after Canny operator 
// using cv::sum(), Char_Parameter.at(i).at(1)
// calculate major and minor axes by searching
	vector<vector<int>> calParameters();

	int getCount();	
};