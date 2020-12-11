#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "View.h"


/**Prints out menu from the user and asks for input
 * 
 * Parameters: 
 *      str(string): String containing names of reports
 *      n(int&): input from user is returned here
 * 
 **/
void View::printMenu(string str, int& n){


  istringstream iss(str);

  cout<< setw(70) << "_______________MENU_______________"<<endl;
  cout<< setw(70) << "Please select one of the following" <<endl<<endl;

  for(string line; getline(iss, line);){
    cout << setw(30 + line.size()) << line << endl;
  }

  cout<< setw(37) <<"0) Exit"<<endl;
  cout<<"Your Selection: ";
  while (!(cin >> n)){
      cout << "Please input a number: ";
      cin.clear();
      cin.ignore(100000,'\n');
  }
}

/**Prints out data
 * 
 * Parameters:
 *      str(String): string to be printed
 * 
 **/ 
void View::printStr(string str){
    cout<<str<<endl;
}

/**Asks for input from user
 * 
 * Parameters:
 *      str(String&): input is returned to this variable
 * 
 **/ 
void View::readStr(string& str){
  cin >> str;
}



/** Prints report to the user
 * 
 * Loops over parameter string and formats report
 * for viewing.
 * 
 * Parameters:
 *      input(String): Raw data of report
 * 
 **/
void View::printReport(string input){
    istringstream iss(input);

    int flagCol = 1;//checks if first row
    int val = 2;//value to be multiplied for whitespace

    //creating extra padding
    cout<<endl<<endl;

    for(string row; getline(iss, row);){
      int flagRow = 1;//checks if item of first

      string tmp;
      stringstream ss(row);

      while(getline(ss, tmp, ' ')){
        if(flagCol == 1){//povide extra space for first row first item
          cout<<setw(20*val)<<tmp;
          val = 1;
        }
        else if(flagRow == 1){//first item of all other row is printed as is
          cout<<setw(20*val)<<tmp;
          flagRow = 0;
        }
        else{
          //Error handling incase value of tmp is NaN
          //Created for generic cases
          //catch statement not accessed for five reports included
          try
          {
            float num = stof(tmp);
            cout<< fixed << setprecision(2) << setw(20*val)<< num ;
          }
          catch(...)
          {
            cout<<setw(20*val)<<tmp;
          }
        }
      }
      //padding after the first row is printed(Column Names)
      if(flagCol == 1){
        cout<<endl<<endl;
        flagCol = 0;
      }
      else{
        cout<<endl;
      }
    }
    //creating extra padding
    cout<<endl<<endl;
}