#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

class pre_process
{
private:
	string Tr;
	string Te;
	string Re;
	string tmp;

	void in_get_yml(const string File_Name);

public:
	pre_process(const char* in_str);
	void Get_Yml();
};