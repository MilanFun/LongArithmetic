#include "BigInteger.h"
#include "Util.h"
using namespace std;

int main()
{
    const char* str1 = "123";
    const char* str2 = "24";
    cout << Util::compare(str1, str2) << endl;
    return 0;
}