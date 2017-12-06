#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct node{
    double wei;
    double val;
    double rat;
}num[10005];

bool cmp(node a, node b)
{
    return a.rat>b.rat;
}


int main()
{
    double sum,upr;
    int len;
    while(cin>>sum>>len>>upr){
        for(int i=0;i<len;i++){
            cin>>num[i].wei>>num[i].val;
            num[i].rat = num[i].val/num[i].wei;
        }
        sort(num,num+len,cmp);  int i=0;    double cat=0;
        while(sum){
            if(sum>=num[i].wei){
                sum-=num[i].wei;
                cat+=num[i].val;
                i++;
            } else{
                cat+=sum*num[i].rat;
                break;
            }
        }
        if(cat>=upr)
            cout << "summon!\n";
        else
            cout << setprecision(3) << fixed <<upr-cat << endl;
    }
}
