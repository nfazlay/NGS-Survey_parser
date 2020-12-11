#ifndef RECORD_H
#define RECORD_H


class Record
{
    public:
        Record(int = 0, string = " ", string = " ", string = " ", int = 0, int = 0);
        int getYear();
        string getRegion();
        string getDegree();
        string getGender();
        int getNumEmployed();
        int getnumGrads();

    private:
        int year;
        string region;
        string degree;
        string gender;
        int numEmployed;
        int numGrads;

};


#endif