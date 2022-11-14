#ifndef UTIL_H
#define UTIL_H

class Util
{
public:
    static char* copy(const char*);
    static int size(const char*);
    static char* reverse(const char*, int);
    static char* verse(const char*);
    static int compare(const char*, const char*);
    static void swap(const char*, const char*);
};

#endif