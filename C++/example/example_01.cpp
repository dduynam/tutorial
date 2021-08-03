#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int res = 0;
    int n = -5;
    cout << pow(2, 3) << endl;
    for (unsigned int i = 0; i < n; ++i)
    {
        res = i;
        //cout << res << endl;
        if (i == 100)
        {
            cout << "n: " << n << endl;
            break;
        }
    }
    cout << res << endl;
    //cout << n << endl;
    return 0;
}