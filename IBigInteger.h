#ifndef IBIGINTEGER_H
#define IBIGINTEGER_H

#include <iostream>
using namespace std;

class IBigInteger 
{
public:
    virtual ~IBigInteger() = 0;

    virtual IBigInteger& operator+(IBigInteger&) = 0;
    virtual IBigInteger& operator-(IBigInteger&) = 0;
    virtual IBigInteger& operator+=(IBigInteger&) = 0;
    virtual IBigInteger& operator-=(IBigInteger&) = 0;
};

#endif