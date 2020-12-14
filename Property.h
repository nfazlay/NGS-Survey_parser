#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Record.h"

/**Template class that stores data of type specified in the template and 
 * 
 * a collection of record pointers of that property
 * 
 * Data Members:
 *      T data: Data of Type T
 *      records: collection of record pointers
 * 
 **/
template <class T>
class Property
{
    public:
        Property(T);
        Property<T>& operator+=(Record*);//adds to the property records
        Record* operator[](int);//returns element at index
        T getData();
        int size();
        
    private:
        T data;
        vector<Record*> records;
};

/** Class contructor that sets the data
 **/
template <class T>
Property<T>::Property(T d){
    data = d;
}

/**Returns the size of the collection
 * 
 * Parameters:
 *      None
 * 
 * Returns:
 *      Size of the collection
 **/
template <class T>
int Property<T>::size(){
    return records.size();
}

/** Returns the type of property
 * 
 * Parameters:
 *      None
 * 
 * Returns:
 *      The property the collection is based on
 **/
template <class T>
T Property<T>::getData(){
    return data;
}

/** Adds to thr end of the collection
 * 
 * Parameters:
 *      None
 * 
 * Returns: 
 *      The current property object
 **/
template <class T>
Property<T>& Property<T>::operator+=(Record* item){
    records.push_back(item);
    return *this;
}

/** Searches collection for records
 * 
 * Parameters:
 *      i(int): Index to find the record
 * 
 * Returns:
 *      Record* at the index in collection
 **/
template <class T>
Record* Property<T>::operator[](int i)
{

    if(i < 0 || i >= size()){
        cout<<"Index out of bounds"<<endl;
        return NULL;
    }
    return records[i];
}

#endif