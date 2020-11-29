#include <iostream>
using namespace std;
#include <string>
#include <vector>

#include "Record.h"

Record::Record(int y, string r, string d, string g, int ne, int ng ){
    year = y;
    region = r;
    degree = d;
    gender = g;
    numEmployed = ne;
    numGrades = ng;
}

int Record::getYear(){
    return year;
}

string Record::getRegion(){
    return region;
}

string Record::getDegree(){
    return degree;
}

string Record::getGender(){
    return gender;
}

int Record::getNumEmployed(){
    return numEmployed;
}


int Record::getnumGrades(){
    return numGrades;
}