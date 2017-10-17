#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int num[30];

double wrong(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else{
        return (n-1)*(wrong(n-1)+wrong(n-2));
    }
}

double all(int n)
{
    if(n==1)
        return 1;
    else
        return n*all(n-1);
}

int main()
{
    int m;
    while(~scanf("%d",&m))
    {
        printf("%.2f%%\n",wrong(m)/all(m)*100);
    }

}
