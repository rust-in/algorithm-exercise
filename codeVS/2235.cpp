#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a;  double b;
    cin >> a >> b;
    int c = round(a*b/10.0);
    if(c%10>=5)
        c = (c/10+1)*10;
    else
        c = c/10*10;
    cout << c;
}
