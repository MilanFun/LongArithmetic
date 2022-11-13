#include "BigInteger.h"
#include "Util.h"

BigInteger::BigInteger()
{

}

BigInteger::BigInteger(const char* num)
{
    char *num1 = Util::copy(num);
    if (num[0] == '-')
    {
        this->setNumber(num1 + 1);
        this->isNeg = true;
    }
    else
    {
        this->setNumber(num1);
        this->isNeg = false;
    }
}

BigInteger::~BigInteger()
{
    delete[] this->number;
}

char* BigInteger::getNumber() const
{
    return this->number;
}

bool BigInteger::isNegative() const
{
    return this->isNeg;
}

void BigInteger::setNumber(const char* num)
{
    this->number = Util::copy(num);
}

void BigInteger::setNegative(bool b)
{
    this->isNeg = b;
}

char* BigInteger::add(const char* a, const char* b)
{
    int size1 = Util::size(a);
    int size2 = Util::size(b);
    int size = size1 < size2 ? size2 : size1;
    int diff = size1 > size2 ? size1 - size2 : size2 - size1;
    char* small = size1 < size2 ? Util::reverse(a, diff) : Util::reverse(b, diff);
    char* huge = size1 < size2 ? Util::reverse(b, 0) : Util::reverse(a, 0);
    
    int memory = 0;
    char* res = new char[size + 1];
    int i = 0;
    for (; i < size; i++)
    {
        int a = huge[i] - '0';
        int b = small[i] - '0';
        int tmp = a + b + memory;
        memory = tmp / 10;
        tmp = tmp % 10;
        res[i] = '0' + tmp;

        if (memory != 0 && i + 1 == size)
        {
            ++i;
            res[i] = '1';
        }
    }

    res[i + 1] = '\0';
    return Util::reverse(res, 0);
}

char* BigInteger::sub(const char* a, const char* b)
{
    int size1 = Util::size(a);
    int size2 = Util::size(b);
    int size = size1 < size2 ? size2 : size1;
    int diff = size1 > size2 ? size1 - size2 : size2 - size1;
    char* small = size1 < size2 ? Util::reverse(a, diff) : Util::reverse(b, diff);
    char* huge = size1 < size2 ? Util::reverse(b, 0) : Util::reverse(a, 0);

    int carry = 0;
    char* res = new char[size + 1];
    int i = 0;
    for(; i < size; i++)
    {
        int a = huge[i] - '0';
        int b = small[i] - '0';
        int tmp = a - b - carry;

        if (tmp < 0)
        {
            tmp = tmp + 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        res[i] = '0' + tmp;
    }

    res[i + 1] = '\0';
    return res;   
}

BigInteger& BigInteger::operator+(BigInteger& bigInteger)
{
    if (this->isNegative() && bigInteger.isNegative() || 
        !this->isNegative() && !bigInteger.isNegative()) 
    {
        this->setNumber(this->add(this->getNumber(), bigInteger.getNumber()));
        this->setNegative(true);
    }
    return *this;
}

BigInteger& BigInteger::operator+=(BigInteger& bigInteger)
{
    return *this + bigInteger;
}

BigInteger& BigInteger::operator-(BigInteger& bigInteger)
{
    if (!this->isNegative() && bigInteger.isNegative())
    {
        this->setNumber(this->add(this->getNumber(), bigInteger.getNumber()));
        this->setNegative(false);
        return *this;
    }
    
    if (this->isNegative() && !bigInteger.isNegative())
    {
        this->setNumber(this->add(this->getNumber(), bigInteger.getNumber()));
        this->setNegative(false);
        return *this;
    }
}

BigInteger& BigInteger::operator-=(BigInteger& bigInteger)
{
    //TO-DO
    return *this;
}

void BigInteger::operator=(const BigInteger& bigInteger)
{
    this->setNumber(bigInteger.getNumber());
    this->setNegative(bigInteger.isNegative());
}

ostream& operator<<(ostream& out, const BigInteger& bigInteger)
{
    if (bigInteger.isNegative()) 
    {
        out << '-' << bigInteger.getNumber();
        return out;
    }
    out << bigInteger.getNumber();
    return out;
}

istream& operator>>(istream& in, BigInteger& bigInteger)
{
    char* num;
    in >> num;
    if (num[0] == '-')
    {
        bigInteger.setNumber(num + 1);
        bigInteger.setNegative(true);
    }
    else
    {
        bigInteger.setNegative(false);
        bigInteger.setNumber(num);
    }
    
    return in;
}