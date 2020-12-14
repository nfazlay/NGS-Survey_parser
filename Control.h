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


/** The control class controls the flow of the program
 * 
 * It initializes the five report generators and adds them
 * to a collection. Outputs menu and asks for input from user.
 * The I/O is handled by the view object
 * 
 **/
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