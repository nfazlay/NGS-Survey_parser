#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "View.h"

void View::printMenu(string str, int& n){


  istringstream iss(str);

  cout<< setw(100) << "_______________MENU_______________"<<endl;
  cout<< setw(100) << "Please select one of the following" <<endl<<endl;

  for(string line; getline(iss, line);){
    cout << setw(60 + line.size()) << line << endl;
  }

  cout<< setw(67) <<"0) Exit"<<endl;
  cout<<"Your Selection: ";
  while (!(cin >> n)){
      cout << "Please input a number: ";
      cin.clear();
      cin.ignore(10000,'\n');
  }
    

}

void View::printStr(string str){
    cout<<str<<endl;
}

void View::readInt(int& n){
  cin >> n;
}

void View::readStr(string& str){
  cin >> str;
}

void View::printReport(string input){
    istringstream iss(input);
    for(string row; getline(iss, row);){
      cout<<row<<endl;
    }
}