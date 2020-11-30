#include <iostream>
#include <iomanip>
#include <cstdlib>

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

ostream& operator<<(ostream& output, const Record& r)
{
  output<<"Record: " << r.year << "  " << setw(10) <<"Region: " << r.region << " "
                     << setw(10) <<"Degree: "<< r.degree << "   Number Employed: "
                     << fixed << setprecision(2) << right << r.numEmployed << "   Number Grades: "
                     << fixed << setprecision(2)  << right << r.numGrades<< endl;
  return output;
}