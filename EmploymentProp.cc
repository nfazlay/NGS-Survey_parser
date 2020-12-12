#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <cmath>
using namespace std;

#include "EmploymentProp.h"


/**Constructor that sets the report name
 **/
EmploymentProp::EmploymentProp(){
    reportName = "The employment proportion for each region, by year";
}


/**Function that shows the employment proportion for 
 * 
 * each region, by year, for all degress and all genders
 * compared to all of Canada
 * 
 * Parameters:
 *      outStr(string&): Address of string where the output is stored
 * 
 * Returns:
 *      None
 * 
**/
void EmploymentProp::execute(string& outStr){
    string rpt = "";//final output which holds the column names initially
    string rptTemp = "";//temporary output which is added to final output

    //Setting flag to print out column only once
    //After first iteration, column headers will not be added
    int flag = 0;

    //Iterating the region collection for region names
    //and year collection for years
    for (int k = 0; k < regionCollection.size(); ++k){
        Property<string>* pr = regionCollection[k];
        string region = pr->getData();
        if(region != "CAN"){//Do not display Canada values as Canada is the region being compares to
            rptTemp += region + " ";
        }
        for (int t = 0; t < yearCollection.size(); ++t){
            Property<int> pd = *yearCollection[t];
            int year = pd.getData();
            if(flag == 0){//first line
                rpt += to_string(year) + " ";
            }

            float total_emp_region = 0;
            float total_emp_overall = 0;
            //iterating records to find total employed for the year and region
            for (int i = 0; i < pd.size(); ++i){
                Record* rcdPtr = pd[i];
                if(rcdPtr->getRegion()== "CAN" && rcdPtr->getGender() == "All"){
                    total_emp_overall += rcdPtr->getNumEmployed();
                }
                else if(rcdPtr->getRegion()== region && rcdPtr->getGender() == "All"){
                    total_emp_region += rcdPtr->getNumEmployed();
                }
            }
            //calculating proportion of employement % by dividing total 
            //employment in region by total employment in Canada for the respected year
            //if total_emp or total_grad is zero, set to zero
            //to handle 0/x error
            if(region != "CAN"){
                float percentEmployed = (total_emp_region != 0) ? (total_emp_region/total_emp_overall)*100: 0;
                float nearest = floor(percentEmployed * 100) / 100; //rounding to two decimal
                rptTemp += to_string(nearest) + " ";
            }
        }
        flag = 1;
        if(region != "CAN"){
            rptTemp += '\n';
        }
    }
    rpt += "\n";
    rpt += rptTemp;//adding to the column headers
    outStr = rpt;  
}