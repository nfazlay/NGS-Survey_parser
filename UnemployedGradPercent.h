#ifndef UNEMPPRCT_H
#define UNEMPPRCT_H

#include "ReportGenerator.h"

/**Concrete class from base report generator that calculates 
 * 
 * the upemployment percentage for each region, for all years, all genders and all degree
 * 
 **/
class UnemployedGradPercent: public ReportGenerator
{
    /** Stores key-value(string-float) pairs for use in report generation
     **/
    class Tuple
    {
        public:
            string key;
            float value;
    };
    public:
        UnemployedGradPercent();
        void execute(string&);
};


#endif