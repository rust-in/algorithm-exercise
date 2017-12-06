#include <iostream>
using namespace std;

/**
最基本的汉诺塔
*/

void han(char a,char b,char c, int n)
{
    if(n==1)
        cout << a << " to " << c << endl;
    else{
        han(a,c,b,n-1);
        cout << a << " to " << c << endl;
        han(b,a,c,n-1);
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        han('A','B','C',n);
        cout << endl;
    }
}
