#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){return a>b;}

int main()
{
    int len;
    while(cin>>len){
        int tmp,gap;    int oper[35]={0};
        for(int i=0;i<len;i++){
            cin>>tmp;
            oper[tmp]++;
        }   cin>>gap;
        long long time = 0;
        sort(oper+1, oper+31,cmp);
        int i,length;
        while(oper[1]>0){
            for(i=1;i<=30;i++)
                if(oper[i]==0)
                    break;
            length = i-1; //此时还剩多少个任务
            if(length>=gap+1)
                for(int j=1;j<=gap+1;j++)
                    oper[j]--;
            else
                for(int j=1;j<i;j++)
                    oper[j]--;
            time+=gap+1;
            sort(oper+1,oper+31,cmp);
        }
        if(length<gap+1)   time -= (gap+1-length); //减去最后一轮多加的思考人生
        cout << time << endl;
    }
}
