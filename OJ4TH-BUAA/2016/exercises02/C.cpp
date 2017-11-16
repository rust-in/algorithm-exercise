#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int time, len;
    int value[1000];
    int weight[1000];
    int all[20005];
    while(cin>> time >> len){
        for(int i=0;i<len;i++)  cin>>value[i]>>weight[i];
        memset(all,0,sizeof(all));
        for(int i=0;i<len;i++)
            for(int t=time;t>=weight[i];t--)
                all[t] = all[t]>(all[t-weight[i]]+value[i])?all[t]:(all[t-weight[i]]+value[i]);
        cout << all[time] << endl;
    }

}
