#ifndef EMPPROP_H
#define EMPPROP_H

#include "ReportGenerator.h"


class EmploymentProp: public ReportGenerator
{
    public:
        EmploymentProp();
        void execute(string&);
};


#endif