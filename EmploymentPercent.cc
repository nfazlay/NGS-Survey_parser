#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

#include "EmploymentPercent.h"


/**Constructor that sets the report name
 **/
EmploymentPercent::EmploymentPercent(){
    reportName = "Employement Percentage by Degree for Each region";
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
void EmploymentPercent::execute(string& outStr){
    string rpt = "";
    string rptTemp = "";

    //Setting flag to print out column only once
    //After first iteration, column headers will not be added
    int flag = 0;

    //Iterating the region collection for row headers
    //and degree collection for column headers
    for (int k = 0; k < regionCollection.size(); ++k){
        Property<string>* pr = regionCollection[k];
        string region = pr->getData();
        rptTemp += region + " ";
        for (int t = 0; t < degreeCollection.size(); ++t){
            Property<string>* pd = degreeCollection[t];
            string degree = pd->getData();
            if(flag == 0){//first line
                rpt += degree + " ";
            }

            float total_grad = 0;
            float total_emp = 0;
            //iterating records to find total Graduates and 
            //total employed for the degree and region
            for (int i = 0; i < records.size(); ++i){
                Record* rcdPtr = records[i];
                if(rcdPtr->getDegree() == degree && rcdPtr->getRegion()== region){
                    total_emp += rcdPtr->getNumEmployed();
                    total_grad += rcdPtr->getnumGrads();
                }
            }
            //calculating percentage
            //if total_emp or total_grad is zero, set to zero
            //to handle 0/x error
            float percentEmployed = (total_emp != 0) ? (total_emp/total_grad)*100: 0;
            rptTemp += to_string(percentEmployed) + " ";
        }
        flag = 1;
        rptTemp += '\n';
    }
    rpt += "\n";
    rpt += rptTemp;
    outStr = rpt;  
}