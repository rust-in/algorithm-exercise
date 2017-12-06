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
        if(a>b) swap(a,b);//使a<b恒成立
        if(b%a==0) break;//必胜态1：b是a的倍数时必胜
        if(b-a>a) break;//必胜态2
        b-=a;//b<2a的情况
        flag=!flag;//必胜态与必败态轮流出现
    }
    flag?printf("Nova\n"):printf("LaoWang\n");
}

int main()
{
    while(cin>>a>>b)
    solve();
    return 0;
}
