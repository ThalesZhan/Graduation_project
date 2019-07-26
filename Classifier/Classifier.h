#include <iostream>

using namespace std;

class Classifier
{
	virtual void check_accuracy() = 0;
	virtual void batching_classify() = 0;
	//virtual void one_classify() = 0;
};