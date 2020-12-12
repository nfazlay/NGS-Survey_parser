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

    //Tuple stores the region along with the percentage of female graduates
    //Using the vactor and Tuple values, we later determine thr top and bottom 3
    vector<Tuple> data;

    //Iterating the region collection for row headers
    //and degree collection for column headers
    for (int k = 0; k < regionCollection.size(); ++k){
        Property<string> pr = *regionCollection[k];
        string region = pr.getData();

        float total_grad = 0;
        float total_FemGrad = 0;
        //iterating records to find total Graduates and 
        //total Female graduates for the region
        //If region is All regions, data is added to the 
        //total_grad vlaues for that region
        //otherwise 
        for (int i = 0; i < pr.size(); ++i){
            Record* rcdPtr = pr[i];
            if(rcdPtr->getGender()== "All"){
                total_grad += rcdPtr->getnumGrads();
            }
            if(rcdPtr->getGender()== "Females"){
                total_FemGrad += rcdPtr->getnumGrads();
            }
        }

        //calculating percentage of female grads by dividing total frmale grads 
        //by all grads for a specific region
        //if total_emp or total_FemGrad is zero, set to zero
        //to handle 0/x error
        float percentGrad = (total_FemGrad != 0) ? (total_FemGrad/total_grad)*100: 0;

        Tuple newTuple;
        newTuple.key = region;
        newTuple.value = percentGrad;
        if(data.size()== 0){//first insertion
            data.push_back(newTuple);
        }
        else{
            //find the insertion point and insert
            //setting flag = 1 when inserted in middle/first
            //else insert at the end
            int flag = 0;
            for(int i =0; i < data.size(); i++){
                if(data[i].value >= percentGrad){
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
    //last index example:
    //if size = 7, i =0, then last index = 7-1-0 = 6
    for(int i =0; i< 3; i++){
        rptTempFirst += data[i].key + " " + to_string(data[i].value) + "\n";
        rptTempLast += data[data.size()-1-i].key + " " + to_string(data[data.size()-1-i].value) + "\n";
    }
    rpt += "Percentage(%)\n" + rptTempLast + "\n" + rptTempFirst;//adding to the column headers
    string output;
    format(rpt, output);
    outStr = output;  
}