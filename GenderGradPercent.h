#ifndef GENGRADPRCT_H
#define GENGRADPRCT_H

#include "ReportGenerator.h"
#include "Tuple.h"


class GenderGradPercent: public ReportGenerator
{
    public:
        GenderGradPercent();
        void execute(string&);
};


#endif