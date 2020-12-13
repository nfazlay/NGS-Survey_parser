#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "View.h"


/**Prints out data
 * 
 * Parameters:
 *      str(String): string to be printed
 * 
 **/ 
void View::printStr(string str){
    cout<<str;
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
  try
  {
    cin >> i;
  }
  catch(const std::exception& e)
  {
    cout << "Ehheee"<< '\n';
  }
  
}