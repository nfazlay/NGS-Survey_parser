#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
#include <string>
#include <vector>

#include "Record.h"

/** Constructor initializes data members
 **/
Record::Record(int y, string r, string d, string g, int ne, int ng ){
    year = y;
    region = r;
    degree = d;
    gender = g;
    numEmployed = ne;
    numGrads = ng;
}

/** Returns year
 **/
int Record::getYear(){
    return year;
}

/** Returns region
 **/
string Record::getRegion(){
    return region;
}

/** Returns degree
 **/
string Record::getDegree(){
    return degree;
}

/** Returns gender
 **/
string Record::getGender(){
    return gender;
}


/** Returns Number of employed
 **/
int Record::getNumEmployed(){
    return numEmployed;
}


/** Returns number og grads
 **/
int Record::getnumGrads(){
    return numGrads;
}