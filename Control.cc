#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

#include "Control.h"


/**Constructor that creates one instance of
 * 
 * each concrete generator report class. 
 * Stores them in collection reports(Data member).
 * 
 **/
Control::Control(){
    
    ReportGenerator* rg; 

    rg = new EmploymentPercent();
    reports.push_back(rg);
    rg = new EmploymentProp();
    reports.push_back(rg);
    rg = new FemaleGrad();
    reports.push_back(rg);
    rg = new GenderGradPercent();
    reports.push_back(rg);
    rg = new UnemployedGradPercent();
    reports.push_back(rg);
}

/** Deaalocates the report generators
 **/
Control::~Control(){
    for(int i =0;i< reports.size(); i++){
        delete reports[i];
    }
}



/** Handles I/O using the view object
 * 
 * Querries the the report generators for raw report data
 * 
 **/
void Control::launch(){
    
    //checks if the file name is correct
    //if the filename is incorrect, asks the user for
    //a valid file name or Loaction
    while(1){
        string fileName;
        view.printStr("Please Enter a filename or location: ");
        view.readStr(fileName);
        bool check = false;
        for(int i =0; i < reports.size(); i++){
            if(!reports[i]->load(fileName)){
                check = true;
                break;
            }
        }
        if(check == false){
            break;
        }
        
    }

    //Querries for name from reports collection and
    //Displays the menu to the screen using the names
    //If user presses 0, exit program
    //Otherwise print the report requested by the user
    while(1){
        int n;
        string names = "";
        for(int i = 0; i < reports.size(); i++){
            names += (to_string(i+1) + ") "+ reports[i]->getName()+"\n");
        }
        view.printMenu(names, n);
        if(n == 0){
            break;
        }
        else if(n < 0 || n > reports.size()){
            view.printStr("Wrong input. Please try again");
        }
        else{
            string rawReport;
            reports[n-1]->execute(rawReport);
            view.printReport(rawReport);
        }
    }
 
}