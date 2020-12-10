#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

#include "FemaleGrad.h"


/**Constructor that sets the report name
 **/
FemaleGrad::FemaleGrad(){
    reportName = "The top 3 and bottom 3 regions for percentage of female graduates";
}


/**Function that shows the female grad percentage for 
 * 
 * each region by calculation female grad/total grad
 * The top 3 and bottom 3 are output
 * 
 * Parameters:
 *      outStr(string&): Address of string where the output is stored
 * 
 * Returns:
 *      None
 * 
**/
void FemaleGrad::execute(string& outStr){
    string rpt = "";
    string rptTempFirst = "";
    string rptTempLast = "";

    //Tuple is a entity class
    vector<Tuple<string, float>> data;

    //Iterating the region collection for row headers
    //and degree collection for column headers
    for (int k = 0; k < regionCollection.size(); ++k){
        Property<string>* pr = regionCollection[k];
        string region = pr->getData();

        float total_grad = 0;
        float total_FemGrad = 0;
        //iterating records to find total Graduates and 
        //total Female graduates for the region
        for (int i = 0; i < records.size(); ++i){
            Record* rcdPtr = records[i];
            if(rcdPtr->getRegion() == region){
                if(rcdPtr->getGender()== "All"){
                    total_grad += rcdPtr->getnumGrads();
                }
                if(rcdPtr->getGender()== "Females"){
                    total_FemGrad += rcdPtr->getnumGrads();
                }
            }
        }

        //calculating percentage
        //Total female graduates/total graduates
        //if total_emp or total_FemGrad is zero, set to zero
        //to handle 0/x error
        float percentGrad = (total_FemGrad != 0) ? (total_FemGrad/total_grad)*100: 0;
        Tuple<string, float> newTuple(region, percentGrad);
        if(data.size()== 0){//first insertion
            data.push_back(newTuple);
        }
        else{
            //find the insertion point and insert
            //setting flag = 1 when inserted in middle/first
            //else insert at the end
            int flag = 0;
            for(int i =0; i < data.size(); i++){
                if(data[i].getValue() >= percentGrad){
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
    for(int i =0; i< 3; i++){
        rptTempFirst += data[i].getKey() + " " + to_string(data[i].getValue()) + "\n";
        rptTempLast += data[data.size()-1-i].getKey() + " " + to_string(data[data.size()-1-i].getValue()) + "\n";
    }
    rpt += "percentage\n" + rptTempLast + "\n" + rptTempFirst;
    outStr = rpt;
}