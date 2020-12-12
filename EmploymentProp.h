#ifndef EMPPROP_H
#define EMPPROP_H

#include "ReportGenerator.h"

/**Calculates the employment proportion for 
 * 
 * each region, by year, for all degress and all genders
 * compared to all of Canada
 * 
 **/
class EmploymentProp: public ReportGenerator
{
    public:
        EmploymentProp();
        void execute(string&);
};


#endif