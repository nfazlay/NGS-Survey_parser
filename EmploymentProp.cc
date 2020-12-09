#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

#include "EmploymentProp.h"


/**Constructor that sets the report name
 **/
EmploymentProp::EmploymentProp(){
    reportName = "The employment proportion for each region, by year";
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
void EmploymentProp::execute(string& outStr){
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
        for (int t = 0; t < yearCollection.size(); ++t){
            Property<int>* pd = yearCollection[t];
            int year = pd->getData();
            if(flag == 0){//first line
                rpt += to_string(year) + " ";
            }

            float total_emp_region = 0;
            float total_emp_overall = 0;
            //iterating records to find total Graduates and 
            //total employed for the degree and region
            for (int i = 0; i < records.size(); ++i){
                Record* rcdPtr = records[i];
                if(rcdPtr->getRegion()== region && rcdPtr->getYear() == year){
                    total_emp_region += rcdPtr->getNumEmployed();
                }
                if(rcdPtr->getRegion()== "CAN" && rcdPtr->getYear() == year){
                    total_emp_overall += rcdPtr->getNumEmployed();
                }
            }
            //calculating percentage
            //if total_emp or total_grad is zero, set to zero
            //to handle 0/x error
            float percentEmployed = (total_emp_region != 0) ? (total_emp_region/total_emp_overall)*100: 0;
            rptTemp += to_string(percentEmployed) + " ";
        }
        flag = 1;
        rptTemp += '\n';
    }
    rpt += "\n";
    rpt += rptTemp;
    outStr = rpt;  
}