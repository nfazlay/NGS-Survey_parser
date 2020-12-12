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

/**Asks for input from user
 * 
 * Parameters:
 *      i(int&): input is returned to this variable
 * 
 **/ 
void View::readInt(int& i){
  cin >> i;
}