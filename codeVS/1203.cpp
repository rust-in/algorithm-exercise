#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    float a,b;
    cin >> a >> b;
    if (a-b<=1e-8&&a-b>=-1e-8)
        cout << "yes";
    else
        cout << "no";
}
