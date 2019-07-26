#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	string str =  "../../../../Chalky/Parameters/Char_";
	str = str + argv[1] + ".yml";

	cv::FileStorage fs(str, cv::FileStorage::READ);
	int count;
	fs["count"] >> count;

	vector<int> data;

	str = argv[1];
	str = "./"+ str + ".txt";
	ofstream file(str);

	string s;
	int rate;
	for (int i = 0; i < count; ++i)
	{	
		s = "sample" + to_string(i);
		fs[s] >> data;
		rate = data.at(3) - data.at(2) / 10 - data.at(1) / 10 - data.at(0) / 10;
		file << rate << "\n"; 
	}

	return 0;
}