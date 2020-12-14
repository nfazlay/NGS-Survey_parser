#ifndef REPORTGEN_H
#define REPORTGEN_H

#include <vector>
#include "Record.h"
#include "Property.h"

/**Base class that is reponsible for report generation
 * 
 * Contains name of report, and partial collections
 * The partial collections store Record* of a specific property
 * 
 * Data Members:
 *      reportName(string): Name of report
 *      records(vector<Record*>): Collection of all records
 *      yearCollection(vector<Property<int>*): Partial collection of years
 *      regionCollection(vector<Property<string>*): Partial collection of region
 *      degreeCollection(vector<Property<string>*): Partial collection of degree
 *      genderCollection(vector<Property<string>*): Partial collection of gender
 * 
 **/
class ReportGenerator
{
    public:
        ReportGenerator();
        ~ReportGenerator();
        bool load(string);
        string getName();
        virtual void execute(string&){};

    protected:
        void format(string, string& );
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