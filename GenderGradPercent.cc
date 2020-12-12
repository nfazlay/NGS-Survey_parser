#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <cmath>
using namespace std;

#include "GenderGradPercent.h"


/**Constructor that sets the report name
 **/
GenderGradPercent::GenderGradPercent(){
    reportName = "Proportion of Graduates for each year by gender";
}


/**Function that shows the graduation percentage for 
 * 
 * each year, by gender, for all regions and all degrees
 * 
 * Parameters:
 *      outStr(string&): Address of string where the output is stored
 * 
 * Returns:
 *      None
 * 
**/
void GenderGradPercent::execute(string& outStr){
    string rpt = "";//final output which holds the column names initially
    string rptTemp = "";//temporary output which is added to final output

    //Setting flag to print out column only once
    //After first iteration, column headers will not be added
    int flag = 0;

    //Iterating the year collection for row headers
    //and gender collection for column headers

    for (int k = 0; k < yearCollection.size(); ++k){

        Property<int>* py = yearCollection[k];
        int year = py->getData();
        rptTemp += to_string(year) + " ";

        for (int t = 0; t < genderCollection.size(); ++t){
            Property<string>* pg = genderCollection[t];
            string gender = pg->getData();
            if(flag == 0){//first line
                if(gender != "All"){
                    rpt += gender + " ";
                }
            }

            //iterating records to find total Graduates per gender 
            //total graduates for all degree and gender
            float total_gender_grad = 0;
            float total_grad = 0;
            for (int i = 0; i < records.size(); ++i){
                Record* rcdPtr = records[i];
                if(rcdPtr->getGender() == "All" && rcdPtr->getYear() == year){
                    total_grad += rcdPtr->getnumGrads();
                }
                else if(rcdPtr->getYear() == year && rcdPtr->getGender()== gender){
                    total_gender_grad += rcdPtr->getnumGrads();
                }
            }
            //calculating percentage by dividing total grad for the gender and 
            //the total grad for the region
            //if total_emp or total_grad is zero, set to zero
            //to handle 0/x error
            if(gender != "All"){
                float percentGrad = (total_gender_grad != 0) ? (total_gender_grad/total_grad)*100: 0;
                float nearest = floor(percentGrad * 100) / 100; 
                rptTemp += to_string(nearest) + " ";
            }
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