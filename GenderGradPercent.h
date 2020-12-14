#ifndef GENGRADPRCT_H
#define GENGRADPRCT_H

#include "ReportGenerator.h"

/**Concrete class from base report generator that 
 * 
 * calculates graduation percentage foreach year, by gender, 
 * for all regions and all degrees
 * 
 **/
class GenderGradPercent: public ReportGenerator
{
    public:
        GenderGradPercent();
        void execute(string&);
};


#endif