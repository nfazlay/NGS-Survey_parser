#ifndef UNEMPPRCT_H
#define UNEMPPRCT_H

#include "ReportGenerator.h"
#include "Tuple.h"


class UnemployedGradPercent: public ReportGenerator
{
    public:
        UnemployedGradPercent();
        void execute(string&);
};


#endif