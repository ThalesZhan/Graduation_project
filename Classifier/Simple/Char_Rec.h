#include "../Classifier.h"
#include <vector>
#include <iostream>

using namespace std;

class Char_Rec: public Classifier
{
private:
	string type;

	//accuracy
	vector<vector<int>> nor_img;
	vector<vector<int>> unor_img;
    int nor_count;
    int unor_count;	

    //batching process
    vector<vector<int>> check_img;
    int count;

    vector<vector<int>> readFile( const string filename1, const string filename2);

public:
	Char_Rec(const char* in_t);
	void check_accuracy();
	void batching_classify();
	//void one_classify();
};