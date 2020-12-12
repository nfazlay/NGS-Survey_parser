#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <cmath>
using namespace std;

#include "EmploymentPercent.h"


/**Constructor that sets the report name
 **/
EmploymentPercent::EmploymentPercent(){
    reportName = "Employement Percentage by degree for each region";
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
    string rpt = "";//final output which holds the column names initially
    string rptTemp = "";//temporary output which is added to final output

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
            Property<string> pd = *degreeCollection[t];
            string degree = pd.getData();
            if(flag == 0){//first row(column headers)
                rpt += degree + " ";
            }

            float total_grad = 0;
            float total_emp = 0;

            //iterating records to find total Graduates and 
            //total employed for the degree and region above
            for (int i = 0; i < pd.size(); ++i){
                Record* rcdPtr = pd[i];
                if(rcdPtr->getRegion()== region && rcdPtr->getGender() == "All"){
                    total_emp += rcdPtr->getNumEmployed();
                    total_grad += rcdPtr->getnumGrads();
                }
            }

            //calculating percentage of employement % by dividing total 
            //employment by total graduates for a year and for a region
            //if total_emp or total_grad is zero, set to zero
            //to handle 0/x error
            float percentEmployed = (total_emp != 0) ? (total_emp/total_grad)*100: 0;
            float nearest = floor(percentEmployed * 100) / 100; 
            rptTemp += to_string(nearest) + " ";
        }
        flag = 1;
        rptTemp += '\n';
    }
    rpt += "\n";
    rpt += rptTemp;//adding to the column headers
    string output;
    format(rpt, output);
    outStr = output;  
}