#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>

using namespace std;


class Record
{
    friend ostream& operator<<(ostream&, const Record&);

    public:
        Record(int = 0, string = " ", string = " ", string = " ", int = 0, int = 0);
        int getYear();
        string getRegion();
        string getDegree();
        string getGender();
        int getNumEmployed();
        int getnumGrades();

    private:
        int year;
        string region;
        string degree;
        string gender;
        int numEmployed;
        int numGrades;

};


#endif