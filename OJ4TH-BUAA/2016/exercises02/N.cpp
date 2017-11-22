#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[55];

bool isLegal(string s)
{
    if(s[0] == '0') return false;
    else
    {
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == '0' && (s[i-1] < '1' || s[i-1] > '2'))
                return false;
            if(s[i] == '#' && s[i + 1] == '#')
                return false;
        }
    }
    return true;
}

long long solveStr(string s)
{
    int l = s.length();
    memset(dp,0,sizeof(dp));

    dp[0] = 1;
    for(int i = 1; i < l; i++)
    {
        if(s[i] == '0')//������ǰһ���ֽ��
        {
            if(i == 1)//��ͷ���'10'��'20'
                dp[i] = dp[i-1];
            else//�ǿ�ͷ���'10'��'20'
                dp[i] = dp[i-2];
        }
        else
        {
            if((s[i-1] == '1' && s[i] <= '9') || (s[i-1] == '2' && s[i]<='6'))//������ǰһ���ֽ��
            {
                if(i != 1)//�ǿ�ͷ���'11'~'19'��'21'~'26'
                    dp[i] = dp[i-1] + dp[i-2];//��ǰһ���ֲ����+���
                else
                    dp[i] = dp[i-1] + 1;//��ǰһ���ֲ����+���
            }
            else
                dp[i] = dp[i-1];//����һ������
        }
    }
    return dp[l-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin >> s && s != "0")
    {
        if(isLegal(s))
        {
            int l = s.length();
            long long ans = 1;
            int start=0;
            for(int i = 0; i < l; i++)
            {
                if(s[i] == '#')
                {
                    ans = ans*solveStr(s.substr(start,i-start));
                    start=i+1;
                }
            }
            ans=ans*solveStr(s.substr(start,l-start));

            printf("%lld\n",ans);
        }
        else printf("0\n");
    }
}
