#ifndef UNEMPPRCT_H
#define UNEMPPRCT_H

#include "ReportGenerator.h"

/**Calculates the upemployment percentage for 
 * 
 * each region, for all years, all genders and all degree
 * 
 **/
class UnemployedGradPercent: public ReportGenerator
{
    /** Stores key-value pairs for use in report generation
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