#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <string>

using namespace std;

#include "List.h"
#include "Record.h"

template <class T>
class Property
{
    public:
        Property(T);
        Property<T>& operator+=(Record*);//adds to the property records
        Record* operator[](int);//returns element at index
        
    private:
        T data;
        List<Record> records;
};

template <class T>
Property<T>::Property(T d){
    data = d;
}

template <class T>
Property<T>& Property<T>::operator+=(Record* item){
    records.add(item);
    return *this;
}

template <class T>
Record* Property<T>::operator[](int i)
{
    int index = i;
    Record* t;

    try
    {
        t = records.get(index);
        if(t == NULL){
            throw "Invalid index";
        }
    }
    catch(...)
    {
        cout<<"Invalid Index"<<endl;
        exit(1);
    }
    return t;
}

#endif