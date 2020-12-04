#ifndef REPORTGEN_H
#define REPORTGEN_H

#include <vector>
#include "Record.h"
#include "List.h"
#include "Property.h"


class ReportGenerator
{
    public:
        ReportGenerator();
        ~ReportGenerator();
        bool load(string);
        string getName();
        void split(const string&, vector<string>&);
        virtual void execute(string&){};

    protected:
        void parsePartial();
        string reportName; 
        vector<Record*> records;
        vector<Property<int>*> yearCollection;
        vector<Property<string>*> regionCollection;
        vector<Property<string>*> degreeCollection; 
};


#endif