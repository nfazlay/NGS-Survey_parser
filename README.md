# FINAL

A C++ program to generates a set of reports based on
data from Canada’s National Graduate Survey (NGS) from the years 2000-2015

## Author

MD Fazlay Rabbi

## Files

Control.cc
Control.h
EmploymentPercent.cc
EmploymentPercent.h
EmploymentProp.cc
EmploymentProp.h
FemaleGrad.cc
FemaleGrad.h
GenderGradPercent.cc
GenderGradPercent.h
grad.dat
main.cc
Makefile
Property.h
Record.cc
Record.h
ReportGenerator.cc
ReportGenerator.h
UmemployedGradPercent.cc
UmemployedGradPercent.h
View.cc
View.h
README.md

## Compiling instruction
Please Use fullscreen for best viewing experience
```bash
make
```

## Running instruction
```bash
./final
```
## Additions
**GenderGradPercent**
    The graduate proportion for all years, by gender

        Each year will be a row, and each type of gender will be a column
        Each cell will show the proportion of graduates, for a specific gender, compared to the total number of graduates in that specific year, employed and unemployed combined, for all years and all degrees combined

**UnemployedGradPercent**
    The unemployed percentage for all years, by gender in order(less to highest)

        Each region will be a row, and there will be one percentage column
        Each cell will show the proportion of graduates who were unemployed, compared to the total number of graduates in that specific region, for all years and all degrees combined

Additionally, please input the file containing the data from the NGS

## Assumptions
    Input for report selection will be an integer
    Gender name(eg: "Females", "All") and region name(eg: "AB", "CAN") does not change





