#ifndef EMPPROP_H
#define EMPPROP_H

#include "ReportGenerator.h"

/**Concrete class from base report generator that calculates
 * 
 * the employment proportion for each region, by year, 
 * for all degress and all genders compared to all of Canada
 * 
 **/
class EmploymentProp: public ReportGenerator
{
    public:
        EmploymentProp();
        void execute(string&);
};


#endif