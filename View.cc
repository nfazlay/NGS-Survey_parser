#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "View.h"

void View::printMenu(string str, int& n){
    string temp;
    cout<<"_______________MENU_______________"<<endl;
    cout<<"Please select one of the following"<<endl;
    cout<<str;
    cout<<"0) Exit"<<endl;
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

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}

void View::printReport(string input){
    cout<<input<<endl;
}