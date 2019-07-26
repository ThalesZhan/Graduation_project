#ifndef REC_H
#define REC_H

#include <iostream>
#include <vector>
using namespace std;

class rec
{
private:
    string type;
    vector<int> check_img;
    string result;
public:
    void rec_read(vector<int> read_img, string read_type);
    string recg_img();
};

#endif // REC_H
