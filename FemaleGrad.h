#ifndef FEMGRAD_H
#define FEMGRAD_H

#include "ReportGenerator.h"


/** Calculates the top 3 and the bottom 3 region for % 
 * 
 * of female graduates
 * 
 **/
class FemaleGrad: public ReportGenerator
{
    /** Stores key-value pairs for use in report generation
     **/
    class Tuple
    {
        public:
            string key;
            float value;
    };
    public:
        FemaleGrad();
        void execute(string&);
};


#endif