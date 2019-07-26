#include <iostream>
#include <vector>
#include "rec.h"

using namespace std;

void rec::rec_read(vector<int> read_img, string read_type)
{
    check_img = read_img;
    type = read_type;
}

string rec::recg_img()
{
    if(type == "Shape")
    {
        double sflag;
        sflag = (double) check_img.at(1) / check_img.at(0);
        if(sflag > 1.4)
            result = "The rice is normal.";
        else if(sflag <= 1.4)
            result = "The rice is unnormal.";
    }
    else if(type == "Chalky")
    {
        int cflag;
        cflag = check_img.at(3) - check_img.at(2) / 10 -
                check_img.at(1) / 10 - check_img.at(0) / 10;
        if(cflag < 0)
            result = "The rice is normal.";
        else if(cflag >= 0)
            result = "The rice is unnormal.";
    }

    return result;
}
