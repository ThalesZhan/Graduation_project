#include<iostream>
#include <fstream>
#include <string>
#include<opencv2/opencv.hpp>
#include "pre_process.h"

using namespace std;

/* Storing images in *.yml files with the format
	cv::Mat*/
/* The first step is to get the path and name of
	images, and the second is to store them into
	*.yml files*/

/* The name of parameter is conposed by two parts, 
  one is Test or Train, the other is Normal or 
  Shape or Chalky. For example, Test_Normal.*/


pre_process::pre_process(const char* in_str)  // Shape or Chalky
{
	tmp = in_str;
	if (tmp == "Shape" | tmp == "Chalky")
	{
		Tr = "Train_" + tmp;
		Te = "Test_" + tmp;
		Re = "reg_" + tmp;
	}
	else if (tmp == "Normal")
	{
		Tr = "Train_" + tmp;
		Te = "Test_" + tmp;
		Re = " ";
	}
}

void pre_process::in_get_yml(const string FileName)
{
	string str = ".yml";
	string file_yml = FileName + str; 							// name of *.yml
	str = "./Pre_Process/yml/";
	file_yml = str + file_yml;

	cv::Mat tmp_img;											// store current image
	cv::FileStorage fs(file_yml, cv::FileStorage::WRITE);		

	// set path
	string path = "./samples/";
	path += FileName;
	str = "/";
	path += str;

	// read images
	str = "_Name.txt";
	string filenames = FileName + str;
	str = "./Pre_Process/File_Name/";
	filenames = str + filenames;

	ifstream fn(filenames);
	string temp;

	if (!fn.is_open())
	{
		cout << "Open " << filenames << "fairly" << endl;
		exit(0);
	}

	int count = 1;
	while(getline(fn, temp))
	{
		string img_name = path + temp;
		tmp_img = cv::imread(img_name, -1);
		if (tmp_img.empty())
		{
			cout << "Open " << temp << "fairly";
			continue;
		}

		str = "Mat" + to_string(count);
		count++;

		fs << str << tmp_img;
	}

	fs << "count" << count-1;										// count images
	fs.release();
}

void pre_process::Get_Yml()
{
	if (tmp == "Shape" | tmp == "Chalky")
	{
		in_get_yml(Tr);
		in_get_yml(Te);
		in_get_yml(Re);
	}
	else if (tmp == "Normal")
	{
		in_get_yml(Tr);
		in_get_yml(Te);
	}
}
