#include <iostream>
using namespace std;
/**
�ݴη�
��֪���������ڷ��η������ǵݹ��ǿ϶��ġ�
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
