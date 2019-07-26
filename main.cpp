#include<iostream>
#include <fstream>
#include <string>
#include<opencv2/opencv.hpp>
#include <cmath>

#include "./Pre_Process/pre_process.h"
#include "./Shape/Img_Pro/Shape_Process.h"
#include "./Chalky/Img_Pro/Chalky_Process.h"
#include "./Classifier/Simple/Char_Rec.h"


//Shape_Process func
void shape(const char* shape_file)  // Test_Shape.yml
{
	Shape_Process process(shape_file);
	int count = process.getCount();
	vector<cv::Mat> cvt = process.cvImg();
	vector<cv::Mat> de = process.Denoising();
	vector<cv::Mat> sp = process.splitBack();

/*	cv::namedWindow("Shape_Chalky_Source_Image",0);
	cv::imshow("Shape_Chalky_Source_Image", process.Source_Img.at(10));
	cv::namedWindow("Shape_Chalky_Gray_Image",0);
	cv::imshow("Shape_Chalky_Gray_Image", cvt.at(10));
	cv::namedWindow("Shape_Chalky_Denoising_Image",0);
	cv::imshow("Shape_Chalky_Denoising_Image", de.at(10));
	cv::namedWindow("Shape_Binary_Image",0);
	cv::imshow("Shape_Binary_Image", sp.at(10));
	cv::Mat img;
	cv::Canny(sp.at(10), img, 0, 255);
	cv::namedWindow("Shape_Canny_Image",0);
	cv::imshow("Shape_Canny_Image", img);
*/
	vector<vector<int>> p1 = process.calParameters();
	vector<vector<int>> p, p0;
	for (int i = 0; i < count; ++i)
	{
		vector<int> tr_p;
		vector<int> tr_p0;
		for (int j = 0; j < 4; ++j)
			tr_p.push_back(p1.at(i).at(j));
		for (int j = 4; j < 6; ++j)
			tr_p0.push_back(p1.at(i).at(j));
		p.push_back(tr_p);
		p0.push_back(tr_p0);
	}

	string str;

	string t_f = shape_file;

	//Store weight and height parameters
	str =  "./Shape/Parameters/Char_wh_";
	str = str + shape_file;

	cv::FileStorage fs(str, cv::FileStorage::WRITE);

	for (int i = 0; i < count; ++i)
	{
		str = "sample" + to_string(i);
		fs << str << p0.at(i);
	}
	fs << "count" << count;


	if (t_f != "reg_Shape.yml")
	{
		//store source parameters
		str = "./Shape/Parameters/Char_";
		str = str + shape_file;

		cv::FileStorage fs0(str, cv::FileStorage::WRITE);

		for (int i = 0; i < count; ++i)
		{
			str = "sample" + to_string(i);
			fs0 << str << p.at(i);
		}
		fs0 << "count" << count;

		//Store normalize parameters
		vector<vector<double>> norm_p;
		cv::Mat pre = cv::Mat::zeros(count, 4, CV_64F);
		cv::Mat tem_c = cv::Mat::zeros(count, 1, CV_64F);
		cv::Mat me,si;
		double mean, sig;

		for (int i = 0; i < count; ++i)
		{
			cv::Mat temp_r = cv::Mat(p.at(i), true);
			cv::Mat temp_rt = temp_r.t();
			temp_rt.copyTo(pre.row(i));
		}

		for (int i = 0; i < 4; ++i)
		{
			pre.col(i).copyTo(tem_c);
			cv::meanStdDev(tem_c, me, si);
			mean = me.at<double>(0);
			sig = si.at<double>(0);
			tem_c = (tem_c - mean) / sig;		
			tem_c.copyTo(pre.col(i));
		}

		double temp[4];
		for (int i = 0; i < count; ++i)
		 {
		 	for (int j = 0; j < 4; ++j)
		 	{
		 		temp[j] = pre.at<double>(i,j);
		 	}
		 	vector<double> v(temp, temp + 4);
		 	norm_p.push_back(v);
		 } 

		str =  "./Shape/Parameters/Norm_";
		str = str + shape_file;

		cv::FileStorage fs1(str, cv::FileStorage::WRITE);

		for (int i = 0; i < count; ++i)
		{
			str = "sample" + to_string(i);
			fs1 << str << norm_p.at(i);
		}

		fs1 << "count" << count;	

		/*
		// normalize2 
		vector<vector<double>> norm_p;
		cv::Mat pre = cv::Mat::zeros(count, 4, CV_64F);
		cv::Mat tem_c = cv::Mat::zeros(count, 1, CV_64F);

		for (int i = 0; i < count; ++i)
		{
			cv::Mat temp_r = cv::Mat(p.at(i), true);
			cv::Mat temp_rt = temp_r.t();
			temp_rt.copyTo(pre.row(i));
		}



		for (int i = 0; i < 4; ++i)
		{
			pre.col(i).copyTo(tem_c);
			cv::normalize(tem_c, tem_c);	
			tem_c.copyTo(pre.col(i));
		}

		double temp[4];
		for (int i = 0; i < count; ++i)
		 {
		 	for (int j = 0; j < 4; ++j)
		 	{
		 		temp[j] = pre.at<double>(i,j);
		 	}
		 	vector<double> v(temp, temp + 4);
		 	norm_p.push_back(v);
		 } 

		str =  "./Shape/Parameters/Norm_";
		str = str + shape_file;

		cv::FileStorage fs1(str, cv::FileStorage::WRITE);


		for (int i = 0; i < count; ++i)
		{
			str = "sample" + to_string(i);
			fs1 << str << norm_p.at(i);
		}

		fs1 << "count" << count;
		*/
	}
}

void chalky(const char* chalky_file)	//Test_Chalky.yml
{
	Chalky_Process process(chalky_file);
	int count = process.getCount();
	vector<cv::Mat> cvt = process.cvImg();
	vector<cv::Mat> de = process.Denoising();
	vector<cv::Mat> sp = process.splitBack();
	vector<cv::Mat> hi = process.getHistogram();


/*	cv::namedWindow("Chalky_Source_Image",0);
	cv::imshow("Chalky_Source_Image", process.Source_Img.at(100));
	cv::namedWindow("Chalky_Gray_Image",0);
	cv::imshow("Chalky_Gray_Image", cvt.at(100));
	cv::namedWindow("Chalky_Denoising_Image",0);
	cv::imshow("Chalky_Denoising_Image", de.at(100));
	cv::namedWindow("Chalky_Split_Image",0);
	cv::imshow("Chalky_Split_Image", sp.at(100));
	process.drawHistogram(100);
*/

	vector<vector<int>> p = process.calParameters();

	//Store parameters
	string str =  "./Chalky/Parameters/Char_";
	str = str + chalky_file;

	cv::FileStorage fs(str, cv::FileStorage::WRITE);

	for (int i = 0; i < count; ++i)
	{
		str = "sample" + to_string(i);
		fs << str << p.at(i);
	}

	fs << "count" << count;

	string t_f = chalky_file;
	if (t_f != "reg_Chalky.yml")
	{
		// normalize
		vector<vector<double>> norm_p;
		cv::Mat pre = cv::Mat::zeros(count, 4, CV_64F);
		cv::Mat tem_c = cv::Mat::zeros(count, 1, CV_64F);
		cv::Mat me,si;
		double mean, sig;

		for (int i = 0; i < count; ++i)
		{
			cv::Mat temp_r = cv::Mat(p.at(i), true);
			cv::Mat temp_rt = temp_r.t();
			temp_rt.copyTo(pre.row(i));
		}

		for (int i = 0; i < 4; ++i)
		{
			pre.col(i).copyTo(tem_c);
			cv::meanStdDev(tem_c, me, si);
			mean = me.at<double>(0);
			sig = si.at<double>(0);
			tem_c = (tem_c - mean) / sig;		
			tem_c.copyTo(pre.col(i));
		}


		double temp[4];
		for (int i = 0; i < count; ++i)
		 {
		 	for (int j = 0; j < 4; ++j)
		 	{
		 		temp[j] = pre.at<double>(i,j);
		 	}
		 	vector<double> v(temp, temp + 4);
		 	norm_p.push_back(v);
		 } 

		str =  "./Chalky/Parameters/Norm_";
		str = str + chalky_file;

		cv::FileStorage fs2(str, cv::FileStorage::WRITE);


		for (int i = 0; i < count; ++i)
		{
			str = "sample" + to_string(i);
			fs2 << str << norm_p.at(i);
		}

		fs2 << "count" << count;	

	/*	// normalize2 
		vector<vector<double>> norm_p;
		cv::Mat pre = cv::Mat::zeros(count, 4, CV_64F);
		cv::Mat tem_c = cv::Mat::zeros(count, 1, CV_64F);

		for (int i = 0; i < count; ++i)
		{
			cv::Mat temp_r = cv::Mat(p.at(i), true);
			cv::Mat temp_rt = temp_r.t();
			temp_rt.copyTo(pre.row(i));
		}



		for (int i = 0; i < 4; ++i)
		{
			pre.col(i).copyTo(tem_c);
			cv::normalize(tem_c, tem_c);	
			tem_c.copyTo(pre.col(i));
		}

		double temp[4];
		for (int i = 0; i < count; ++i)
		 {
		 	for (int j = 0; j < 4; ++j)
		 	{
		 		temp[j] = pre.at<double>(i,j);
		 	}
		 	vector<double> v(temp, temp + 4);
		 	norm_p.push_back(v);
		 } 

		str =  "./Chalky/Parameters/Norm_";
		str = str + chalky_file;

		cv::FileStorage fs1(str, cv::FileStorage::WRITE);


		for (int i = 0; i < count; ++i)
		{
			str = "sample" + to_string(i);
			fs1 << str << norm_p.at(i);
		}

		fs1 << "count" << count;
	*/	
	}
}

int main(int argc, char const *argv[])
{
	string tmp_argv = argv[1];

	//Process the source file, .bmp -> .yml
	pre_process p1("Shape");
	p1.Get_Yml();
	pre_process p2("Chalky");
	p2.Get_Yml();
	pre_process p3("Normal");
	p3.Get_Yml();	

	//Image_Process
	if (tmp_argv == "Shape")
	{
		//Shape_Process
		shape("Test_Shape.yml");
		shape("Test_Normal.yml");
		shape("Train_Shape.yml");
		shape("Train_Normal.yml");
		shape("reg_Shape.yml");
	}
	else if (tmp_argv == "Chalky")
	{
		//Chalky_Process
		chalky("Test_Chalky.yml");
		chalky("Test_Normal.yml");
		chalky("Train_Chalky.yml");
		chalky("Train_Normal.yml");
		chalky("reg_Chalky.yml");
	}

	//recogniazation
	Char_Rec test(argv[1]);
	test.check_accuracy();
	test.batching_classify();

//	cv::waitKey(0);
	
	return 0;
}