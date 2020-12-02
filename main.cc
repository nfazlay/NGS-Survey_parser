#include <iostream>
#include <cstdlib>

using namespace std;
#include <string>

#include "Record.h"
#include "List.h"
#include "Property.h"
#include "ReportGenerator.h"

int main(){
    // List<Record> records;
    ReportGenerator rg;
    Record* r = new Record(2000, "AB", "Bachelor's", "All", 6900, 7500);
    // records.add(r);
    // records.add(r);
    // records.add(r);
    // r = new Record(2000, "AB", "Bachelor's", "All", 6900, 7900);
    // records.add(r);
    // cout<< *r;
    // r = records.get(4);
    Property<int> prop(2000);
    prop += r;
    prop += r;
    prop += r;
    r = prop[2];
    cout<<*r;
    rg.load("grad.dat");

    //cout<< *r;
    return 0;
}