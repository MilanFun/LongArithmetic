#include <Util.h>

char* Util::copy(const char* str)
{
    int s = size(str);
    char* result = new char[s + 1];
    int i = 0;
    for (; *str != '\0'; str++) {
        result[i] = *str;
        i++;
    }
    result[i + 1] = '\0';
    return result;
}

int Util::size(const char* str)
{
    int result = 0;
    for (; *str != '\0'; str++) result++;
    return result;
}

char* Util::reverse(const char* str, int zero)
{
    int s = size(str);
    int new_size = s + zero - 1;
    char* result = new char[new_size + 1];
    int j = s - 1;
    int i = 0;
    for (; j >= 0; j--)
    {
        result[i] = str[j];
        i++;
    }
    for(; i <= new_size; i++) result[i] = '0';
    result[i + 1] = '\0';
    return result;
}

int Util::compare(const char* a, const char* b)
{
    int size1 = Util::size(a);
    int size2 = Util::size(b);

    if (size1 > size2)
    {
        return 1;
    }
    else if (size1 < size2)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < size1; i++)
        {
            int h = a[i] - '0';
            int j = b[i] - '0';

            if (h > j) 
            {
                return 1;
            }
            else if (h < j)
            {
                return -1;
            }
        }
    }
    return 0;
}

void Util::swap(const char* a, const char* b)
{
    const char* tmp = a;
    a = b;
    b = tmp;
}