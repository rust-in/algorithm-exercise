#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int a,b;
void solve()
{
    bool flag=true;
    while(1)
    {
        if(a>b) swap(a,b);//ʹa<b�����
        if(b%a==0) break;//��ʤ̬1��b��a�ı���ʱ��ʤ
        if(b-a>a) break;//��ʤ̬2
        b-=a;//b<2a�����
        flag=!flag;//��ʤ̬��ذ�̬��������
    }
    flag?printf("Nova\n"):printf("LaoWang\n");
}

int main()
{
    while(cin>>a>>b)
    solve();
    return 0;
}
