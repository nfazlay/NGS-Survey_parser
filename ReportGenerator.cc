#include <iostream>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;


#include "ReportGenerator.h"


/**Constructor
 **/
ReportGenerator::ReportGenerator(){
    reportName  = " ";
}

/**Destructor- deallocated allocated memory
 **/
ReportGenerator::~ReportGenerator(){
    //deallocate record memory here
    for (auto i = records.begin(); i != records.end(); ++i){
        delete *i;
    } 
}

string ReportGenerator::getName(){
    return reportName;
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

/**Helper function that populates the partial collections
 * 
 * Parameters:
 *      None
 * 
 * Returns:
 *      None
 * 
**/
void ReportGenerator::parsePartial(){
    int year;
    string region, degree, gender;
    //Checks if the property already exist
    //add to current property if property exists
    //create new property elsewise
    int flag = 0;

    for (int i = 0.; i < records.size(); ++i){
        Record* rcdPtr = records[i];
        year = rcdPtr->getYear();
        degree = rcdPtr->getDegree();
        region = rcdPtr->getRegion();
        gender = rcdPtr->getGender();

        //iterates the partial year collections and checks if 
        //collection exists
        for (int k = 0; k < yearCollection.size(); ++k){
            Property<int>* prpPtrTemp = yearCollection[k];
            int data = prpPtrTemp->getData();
            if(year == data){//Property already exists
                *(prpPtrTemp)+=rcdPtr;
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            //we get here if no instance of current data is
            //found in the partial collection
            //Create new property, add record to it and add to partial collection
            Property<int>* newProp = new Property<int>(year);
            *(newProp)+= rcdPtr;
            yearCollection.push_back(newProp);
        }
        flag = 0;//set flag to zero for next property type

        //iterates the partial region collection and checks if 
        //collection exists
        for (int k = 0; k < regionCollection.size(); ++k){
            Property<string>* prpPtrTemp = regionCollection[k];
            string data = prpPtrTemp->getData();
            if(region == data){//Property already exists
                *(prpPtrTemp)+=rcdPtr;
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            //we get here if no instance of current data is
            //found in the partial collection
            //Create new property, add record to it and add to partial collection
            Property<string>* newProp = new Property<string>(region);
            *(newProp) += rcdPtr;
            regionCollection.push_back(newProp);
        }
        flag = 0;

        //iterates the partial degree collections and checks if 
        //collection exists
        for (int k = 0; k < degreeCollection.size(); ++k){
            Property<string>* prpPtrTemp = degreeCollection[k];
            string data = prpPtrTemp->getData();
            if(degree == data){//Property already exists
                *(prpPtrTemp)+=rcdPtr;
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            //we get here if no instance of current data is
            //found in the partial collection
            //Create new property, add record to it and add to partial collection
            Property<string>* newProp = new Property<string>(degree);
            *(newProp)+= rcdPtr;
            degreeCollection.push_back(newProp);
        }
        flag = 0;

        //iterates the partial gender collections and checks if 
        //collection exists
        for (int k = 0; k < genderCollection.size(); ++k){
            Property<string>* prpPtrTemp = genderCollection[k];
            string data = prpPtrTemp->getData();
            if(gender == data){//Property already exists
                *(prpPtrTemp)+=rcdPtr;
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            //we get here if no instance of current data is
            //found in the partial collection
            //Create new property, add record to it and add to partial collection
            Property<string>* newProp = new Property<string>(gender);
            *(newProp)+= rcdPtr;
            genderCollection.push_back(newProp);
        }
        flag = 0;
    }
}


bool ReportGenerator::load(string filePath){
    fstream newfile;
    newfile.open(filePath,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;

        while(getline(newfile, tp)){  //read data from file object and put it into string.
            vector<string> separated;//holds splitted data
            split(tp, separated);
            //get value from vector
            int year = stoi(separated[0]);
            string region = separated[1];
            string degree = separated[2];
            string gender = separated[3];
            int numEmployed = stoi(separated[4]);
            int numGrads = stoi(separated[5]);

            //create record and add to vector of records
            Record* newRecord = new Record(year, region, degree, gender, numEmployed, numGrads);
            records.push_back(newRecord);
        }
        newfile.close();//close the file object.
        parsePartial();
    }
    else{
        cout<<"*******Could not open file******"<<endl;
        return false;
    }
    return true;
}