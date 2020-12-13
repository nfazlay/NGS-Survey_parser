#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/** Handles Input/Output by reading input from the user and print 
 * output to the screen. Autput must be formatted by the entity
 * and control objects as large strings.
 **/
class View
{
    public:
        void printStr(string);
        void readStr(string&);
        void readInt(int&);
};


#endif