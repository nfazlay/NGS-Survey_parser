#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

class View
{
    public:
        void printMenu(string, int&);
        void printReport(string);
        void printStr(string);
        void readInt(int&);
        void readStr(string&);
};


#endif