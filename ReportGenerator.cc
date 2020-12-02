#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
#include <string>
#include <vector>

#include "ReportGenerator.h"

ReportGenerator::ReportGenerator(){
    reportName  = "";
}

/**Helper function splits string passed
 * 
 * Parameters:
 *      data(string): String to be splitted 
 *      c(vector<string>): vector to return splitted string 
 * 
 * Returns:
 *      None
 * 
 **/
void ReportGenerator::split(const string& data, vector<string>& c){
    string tmp;
    stringstream ss(data);
    while(getline(ss,tmp,' ')) {
        c.push_back(tmp);
    }
}


bool ReportGenerator::load(string filePath){
    fstream newfile;
    newfile.open(filePath,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        int i = 0;
        while(getline(newfile, tp)){  //read data from file object and put it into string.
            vector<string> separated;//holds splitted data
            split(tp, separated);
            //get value from vector
            int year = stoi(separated[0]);
            string region = separated[1];
            string degree = separated[2];
            string gender = separated[3];
            int numEmployed = stoi(separated[4]);
            int numGrades = stoi(separated[5]);

            //create record
            Record* newRecord = new Record(year, region, degree, gender, numEmployed, numGrades);
            records.push_back(newRecord);
            cout<<*records[i];
            i++;
        }
        newfile.close();   //close the file object.
    }
    else{
        cout<<"Could not open file"<<endl;
    }
    return true;
}