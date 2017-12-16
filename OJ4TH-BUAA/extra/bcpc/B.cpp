#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define len_x 23

vector< map<int,int> > ahh;
long add[len_x+1];
string name;

int main()
{
    ios::sync_with_stdio(false);
    int time;   scanf("%d",&time);
    map<int,int> init;
    for(int i=0;i<=23;i++)  ahh.push_back(init);
    while(time--){
        for(int i=0;i<=23;i++)  ahh[i].clear();
        for(int i=0;i<=23;i++)  add[i]=0;
        cin >> name;
        int len = name.length();
        for(int i=0;i<len;i++){
            int sum=0;
            for(int j=0;j<=min(i,len_x-1);j++){
                char now = name[i-j];
                if(now=='1')
                    sum += pow(2,j);
                if(ahh[j+1][sum]==0){
                    ahh[j+1][sum]=1;
                    add[j+1]+=sum;
                }
            }
        }
        for(int i=1;i<=23;i++)
            if(ahh[i][0]==0||add[i]<((pow(2,i)-1)*pow(2,i)/2))
            {
                printf("%d\n",i);
                break;
            }
    }
}
