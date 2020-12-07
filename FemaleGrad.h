#ifndef FEMGRAD_H
#define FEMGRAD_H

#include "ReportGenerator.h"
#include "Tuple.h"


class FemaleGrad: public ReportGenerator
{
    public:
        FemaleGrad();
        void execute(string&);
};


#endif