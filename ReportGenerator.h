#ifndef REPORTGEN_H
#define REPORTGEN_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;
#include "Record.h"
#include "List.h"
#include "Property.h"


class ReportGenerator
{
    public:
        ReportGenerator();
        bool load(string);
        void split(const string&, vector<string>&);

    private:
        string reportName; 
        vector<Record*> records;
        List<Property<int>> yearCollection;
        List<Property<string>> regionCollection;
        List<Property<string>> degreeCollection; 

};


#endif