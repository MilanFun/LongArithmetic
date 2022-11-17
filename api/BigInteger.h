#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
using namespace std;

class BigInteger
{
public:
    BigInteger();
    BigInteger(const char* num);
    ~BigInteger();

    char* getNumber() const;
    bool isNegative() const;
    void setNumber(const char*);
    void setNegative(bool);

    BigInteger& operator+=(BigInteger&);
    BigInteger& operator-=(BigInteger&);
    BigInteger& operator+(BigInteger&);
    BigInteger& operator-(BigInteger&);
    void operator=(const BigInteger&);

    friend ostream& operator<<(ostream&, const BigInteger&);
    friend istream& operator>>(istream&, BigInteger&);
private:
    char* add(const char*, const char*);
    char* sub(const char*, const char*);
private:
    char* number;
    bool isNeg = false;
};

#endif