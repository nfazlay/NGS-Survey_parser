#ifndef CONTROL_H
#define CONTROL_H

#include <vector>

#include "ReportGenerator.h"
#include "EmploymentPercent.h"
#include "EmploymentProp.h"
#include "FemaleGrad.h"
#include "GenderGradPercent.h"
#include "UnemployedGradPercent.h"
#include "View.h"



class Control
{
    public:
        Control();
        ~Control();
        void launch();
    private:
        vector<ReportGenerator*> reports;
        View view;
};


#endif