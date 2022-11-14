#include "../api/BigInteger.h"
#include "../api/Util.h"
using namespace std;

int main()
{
    BigInteger A("9999");
    BigInteger B("9999");
    cout << A + B << endl;
    return 0;
}