#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	string str =  "../../../Chalky/Parameters/Char_";
	str = str + argv[1] + ".yml";

	cv::FileStorage fs(str, cv::FileStorage::READ);
	int count;
	fs["count"] >> count;

	vector<int> data;

	str = argv[1];
	str = "./Ma_"+ str + ".txt";
	ofstream file(str);

	string s;
	for (int i = 0; i < count; ++i)
	{	
		s = "sample" + to_string(i);
		fs[s] >> data;
		file << data.at(0) << " " << data.at(1) << " " << data.at(2) << " " << data.at(3) << "\n"; 
	}

	return 0;
}