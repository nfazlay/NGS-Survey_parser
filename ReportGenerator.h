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
        void parsePartial(char&);
        string reportName; 
        vector<Record*> records;
        vector<Property<int>*> yearCollection;
        vector<Property<string>*> regionCollection;
        vector<Property<string>*> degreeCollection; 
};


#endif