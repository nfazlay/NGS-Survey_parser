#ifndef EMPPRTC_H
#define EMPPRTC_H

#include "ReportGenerator.h"


class EmploymentPercent: public ReportGenerator
{
    public:
        EmploymentPercent();
        void execute(string&);
};


#endif