#ifndef RECORD_H
#define RECORD_H


/** Stores records values from input file
 * 
 * Records consist of year, degree, gender, number 
 * employed and total grads
 * 
 * Data members:
 *      year(int): Year
 *      region(string): region
 *      degree(string): degree
 *      gender(string): gender
 *      numEmployed(int): Number of Employed
 *      numGrads(int): Number of Graduates
 * 
 **/
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