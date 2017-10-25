#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a,b,c,d,cnt=0;
    int abc = 100000000;
    srand(time(NULL));
    for(int i=0;i<abc;i++){
        a = double(rand()) / RAND_MAX;
        b = double(rand()) / RAND_MAX;
        if(b-(sin(a)/a)<0)
            cnt++;
    }
    cout << setprecision(3) << fixed << cnt/abc << endl;
}
