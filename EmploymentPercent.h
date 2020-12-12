#ifndef EMPPRTC_H
#define EMPPRTC_H

#include "ReportGenerator.h"

/**Calculates the employment percentage for 
 * 
 * each region, by degree, for all years and all genders
 * 
 **/
class EmploymentPercent: public ReportGenerator
{
    public:
        EmploymentPercent();
        void execute(string&);
};


#endif