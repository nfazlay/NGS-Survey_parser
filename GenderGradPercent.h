#ifndef GENGRADPRCT_H
#define GENGRADPRCT_H

#include "ReportGenerator.h"

/**Function that shows the graduation percentage for 
 * 
 * each year, by gender, for all regions and all degrees
 * 
 **/
class GenderGradPercent: public ReportGenerator
{
    public:
        GenderGradPercent();
        void execute(string&);
};


#endif