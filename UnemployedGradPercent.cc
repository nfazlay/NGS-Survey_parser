#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <cmath>
using namespace std;

#include "UnemployedGradPercent.h"


/**Constructor that sets the report name
 **/
UnemployedGradPercent::UnemployedGradPercent(){
    reportName = "Greatest unemployment rate in grads by region(lowest to highest)";
}


/**Function that shows the employment percentage for 
 * 
 * each region, by degree, for all years and all genders
 * 
 * Parameters:
 *      outStr(string&): Address of string where the output is stored
 * 
 * Returns:
 *      None
 * 
**/
void UnemployedGradPercent::execute(string& outStr){
    string rpt = "";//final output which holds the column names initially
    string rptTemp = "";//temporary output which is added to final output

    //Setting flag to print out column only once
    //After first iteration, column headers will not be added
    int flag = 0;

    vector<Tuple<string, float>> data;

    //Iterating the region collection for row headers
    //and degree collection for column headers
    for (int k = 0; k < regionCollection.size(); ++k){

        Property<string>* pr = regionCollection[k];
        string region = pr->getData();

        float total_grad = 0;
        float total_emp = 0;
        //iterating records to find total Graduates and 
        //total employed for the degree and region
        for (int i = 0; i < records.size(); ++i){
            Record* rcdPtr = records[i];
            if(rcdPtr->getRegion()== region && rcdPtr->getGender() == "All"){
                total_emp += rcdPtr->getNumEmployed();
                total_grad += rcdPtr->getnumGrads();
            }
        }
        //calculating percentage
        //if total_emp or total_grad is zero, set to zero
        //to handle 0/x error
        float percentUnemployed = (total_grad != 0) ? ((total_grad - total_emp)/total_grad)*100: 0;
        float nearest = floor(percentUnemployed * 100) / 100; 


        Tuple<string, float> newTuple(region, nearest);
        if(data.size()== 0){//first insertion
            data.push_back(newTuple);
        }
        else{
            //find the insertion point and insert
            //setting flag = 1 when inserted in middle/first
            //else insert at the end
            int flag = 0;
            for(int i =0; i < data.size(); i++){
                if(data[i].getValue() >= nearest){
                    data.insert(data.begin()+i, newTuple);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                data.push_back(newTuple);
            }
        }
    }

    //build string from the tuples
    //iterate three times to find the first three and the last three
    for(int i =0; i< data.size(); i++){
        rptTemp += data[i].getKey() + " " + to_string(data[i].getValue()) + "\n";
        
    }
    rpt += "Percentage(%)\n" + rptTemp;
    outStr = rpt; 
}