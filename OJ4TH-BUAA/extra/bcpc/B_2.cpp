#include <cstdio>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
//using namespace __gnu_cxx;
#define len_x 23

//int rec[8388608]; //2^23
//string name;
char name[4500005];

int main()
{
//    ios::sync_with_stdio(false);
    int time;   scanf("%d",&time);
    while(time--){
        scanf("%s",name);
        int len = strlen(name);

        for(int i=1;i<=len_x;i++){
//            rec.clear();
            long *rec = new long[8388608];
//            hash_map<int,int> rec;
//            memset(rec, 0, sizeof(rec));
            int cnt=0;
            long sum=0;
            for(int j=0;j<i;j++)
                sum = (sum*2 + name[j]-'0');
            for(int j=i;j<=len;j++){
                if(rec[sum]==0){
                    rec[sum]=1;
                    cnt++;
                }

                if(cnt==(1<<i)) break;
                sum = (sum - (name[j-i]-'0')*(1<<(i-1)))*2 + name[j]-'0';
            }
            delete rec;
            if(cnt<(1<<i)){
                printf("%d\n",i);
                break;
            }
//            cout << i << " " << cnt << endl;
        }
    }
}
