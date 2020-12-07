#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>
using namespace std;
#include <cstdlib>

template <class T, class V>
class Tuple
{
    public:
        Tuple(T, V);
        T getKey();
        V getValue();
    private:
        T key;
        V value;

};

template <class T, class V>
Tuple<T, V>::Tuple(T t, V v){
    key = t;
    value = v;
}

template <class T, class V>
T Tuple<T, V>::getKey(){
    return key;
}

template <class T, class V>
V Tuple<T, V>::getValue(){
    return value;
}


#endif