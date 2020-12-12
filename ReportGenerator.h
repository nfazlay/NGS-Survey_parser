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
        void format(string, string& );
        virtual void execute(string&){};

    protected:
        void split(const string&, vector<string>&);
        void parsePartial();
        string reportName; 
        vector<Record*> records;
        vector<Property<int>*>    yearCollection;
        vector<Property<string>*> regionCollection;
        vector<Property<string>*> degreeCollection;
        vector<Property<string>*> genderCollection;
};


#endif