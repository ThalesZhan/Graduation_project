#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
#include "Char_Rec.h"
using namespace std;

vector<vector<int>> Char_Rec::readFile( const string filename1, const string filename2) // Chalky, Char_Test_Chalky
{
	string path = "./" + filename1 + "/Parameters/";
    string file = path + filename2 + ".yml";
    cv::FileStorage fs(file, cv::FileStorage::READ);

    int tcount;
    fs["count"] >> tcount;

    vector<vector<int>> p2;
    vector<int> p;
    string str;

    for (int i = 0; i < tcount; ++i)
    {
        str = "sample" + to_string(i);
        fs[str] >> p;
        p2.push_back(p);
    }
    return p2;
}

Char_Rec::Char_Rec(const char* in_t)
{
	type = in_t;

	if (type == "Chalky")
	{
        string nor = "Char_Train_Normal";
        string unor = "Char_Train_" + type;
        nor_img = readFile(type, nor);
        unor_img = readFile(type, unor);
		nor_count = nor_img.size();
        unor_count = unor_img.size();

        string rec_s = "Char_reg_" + type;
        check_img = readFile(type, rec_s);
        count = check_img.size();
	}
	else if (type == "Shape")
	{
        string nor = "Char_wh_Train_Normal";
        string unor = "Char_wh_Train_" + type;
        nor_img = readFile(type, nor);
        unor_img = readFile(type, unor);
		nor_count = nor_img.size();
        unor_count = unor_img.size();

        string rec_s = "Char_wh_reg_" + type;
        check_img = readFile(type, rec_s);
        count = check_img.size();
	}
}

void Char_Rec::check_accuracy()
{
	if (type == "Chalky")
	{
		int nor_nor = 0, unor_unor = 0;
		int flag;

        for (int i = 0; i < nor_count; ++i)
        {
            flag = nor_img.at(i).at(3) - nor_img.at(i).at(2) / 10 - nor_img.at(i).at(1) /10 - nor_img.at(i).at(0) / 10;
            if (flag < 0)
                nor_nor += 1;
        }
        for (int i = 0; i < unor_count; ++i)
        {
            flag = unor_img.at(i).at(3) - unor_img.at(i).at(2) / 10 - unor_img.at(i).at(1) /10 - unor_img.at(i).at(0) / 10;
            if (flag >= 0)
                unor_unor += 1;
        }

        double nor_rate = (double) nor_nor / nor_count;
        double unor_rate = (double) unor_unor / unor_count;

        ofstream rfile("./Classifier/Simple/Data/Chalky_rec_Rate.txt");
        rfile << "The number of samples of chalky rice : " << unor_count << "\n";
        rfile << "The number of samples of normal rice : " << nor_count << "\n";
        rfile << "The number of chalky rice being recognization : " << unor_unor 
            << "  The correct rate : " << unor_rate << "\n";
        rfile << "The number of normal rice being recognization : " << nor_nor 
            << "  The correct rate : " << nor_rate << "\n";
	}
	else if (type == "Shape")
	{
		int nor_nor = 0, unor_unor = 0;
		double flag;

		for (int i = 0; i < nor_count; ++i)
        {
            flag = (double) nor_img.at(i).at(1) / nor_img.at(i).at(0);
            if (flag > 1.4)
                nor_nor += 1;
        }
        for (int i = 0; i < unor_count; ++i)
        {
            flag = (double) unor_img.at(i).at(1) / unor_img.at(i).at(0);
            if (flag <= 1.4)
                unor_unor += 1;
        }

        double nor_rate = (double) nor_nor / nor_count;
        double unor_rate = (double) unor_unor / unor_count;

        ofstream rfile("./Classifier/Simple/Data/Shape_rec_Rate.txt");
        rfile << "The number of samples of unnormal rice : " << unor_count << "\n";
        rfile << "The number of samples of normal rice : " << nor_count << "\n";
        rfile << "The number of unnormal rice being recognization : " << unor_unor 
            << "  The correct rate : " << unor_rate << "\n";
        rfile << "The number of normal rice being recognization : " << nor_nor 
            << "  The correct rate : " << nor_rate << "\n";  
	}
}

void Char_Rec::batching_classify()
{
	if (type == "Chalky")
	{
        ofstream file("./Classifier/Simple/Data/Chalky_Consequence.txt");
        int ch;
        string str;

        for (int i = 0; i < count; ++i)
        {
            str = "sample" + to_string(i);
            ch = check_img.at(i).at(3) - check_img.at(i).at(2) / 10 - check_img.at(i).at(1) / 10 - check_img.at(i).at(0) / 10;
            if (ch >= 0)
            {
                file << str << " is chalky!" << "\n";
            }
            else if (ch < 0)
            {
                file << str << " is normal!" << "\n";
            }
        }		
	}
	else if (type == "Shape")
	{
        ofstream file("./Classifier/Simple/Data/Shape_Consequence.txt");
        double ch;
        string str;

        for (int i = 0; i < count; ++i)
        {
            str = "sample" + to_string(i);
            ch = (double) check_img.at(i).at(1) / check_img.at(i).at(0);
            if (ch <= 1.4)
            {
                file << str << " is unnormal!" << "\n";
            }
            else if (ch > 1.4)
            {
                file << str << " is normal!" << "\n";
            }
        }		
	}
}