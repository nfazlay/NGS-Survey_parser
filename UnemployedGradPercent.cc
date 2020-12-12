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
    reportName = "Unemployment rate in grads by region(lowest to highest)";
}


/**Function that shows the upemployment percentage for 
 * 
 * each region, for all years, all genders and all degree
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

    vector<Tuple> data;

    //and region collection for row headers
    for (int k = 0; k < regionCollection.size(); ++k){

        Property<string> pr = *regionCollection[k];
        string region = pr.getData();

        float total_grad = 0;
        float total_emp = 0;
        //iterating records in property to find total Graduates and 
        //total employed for the degree and region
        for (int i = 0; i < pr.size(); ++i){
            Record* rcdPtr = pr[i];
            if(rcdPtr->getGender() == "All"){
                total_emp += rcdPtr->getNumEmployed();
                total_grad += rcdPtr->getnumGrads();
            }
        }
        //calculating percentage 
        //if total_emp or total_grad is zero, set to zero
        //to handle 0/x error
        float percentUnemployed = (total_grad != 0) ? ((total_grad - total_emp)/total_grad)*100: 0;
        float nearest = floor(percentUnemployed * 100) / 100; 


        Tuple newTuple;
        newTuple.key = region;
        newTuple.value = nearest;

        if(data.size()== 0){//first insertion
            data.push_back(newTuple);
        }
        else{
            //find the insertion point and insert
            //setting flag = 1 when inserted in middle/first
            //else insert at the end
            int flag = 0;
            for(int i =0; i < data.size(); i++){
                if(data[i].value >= nearest){
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
    //iterate to get data from sorted vector
    for(int i =0; i< data.size(); i++){
        rptTemp += data[i].key + " " + to_string(data[i].value) + "\n";   
    }
    rpt += "Percentage(%)\n" + rptTemp;
    string output;
    format(rpt, output);
    outStr = output;  
}