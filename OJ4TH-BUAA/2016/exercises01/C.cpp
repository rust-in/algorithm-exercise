#include <stdio.h>
using namespace std;

void feb(int &a,int &b,int &c,long n)
{
    if(n>1){
        feb(a,b,c,n/2);
        int an = (a*a+b*b) % 10007;
        int bn = (b*a+c*b) % 10007;
        int cn = (b*b+c*c) % 10007;
        if(n%2){
            a = (an+bn) % 10007;
            b = an;
            c = bn;
        }
        else{
            a = an;
            b = bn;
            c = cn;
        }
        return;
    }
    else
        a=b=1;  c=0;
}

int main()
{
    long n;
    while(~scanf("%ld",&n))
    {
        int a,b,c;
        feb(a,b,c,n);
        printf("%d\n",b);
    }
}
