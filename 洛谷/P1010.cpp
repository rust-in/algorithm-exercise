#include <iostream>
using namespace std;
/**
幂次方
不知道属不属于分治法，但是递归是肯定的。
*/
void pt(long num)
{
    int t=0;
    while(num){
        long a=1,b=0;
        while(a<=num)
        {
            b++;
            a*=2;
        }
        b--;a/=2;
        if(t)
            cout<<"+";
        else
            t=1;

        if(b==0)    cout << "2(0)";
        else if(b==1) cout << "2";
        else
        {
            cout << "2("; pt(b); cout<<")";
        }
        num-=a;
    }
}

int main()
{
    long num;
    while(cin>>num)
    {
        pt(num);
        cout<<endl;
    }


}
