#include <bits/stdc++.h>

using namespace std;
#define max_size 10000

struct Node{
double v;
double t;
double time;
};

bool cmp(Node a,Node b)
{
    return a.time<b.time;
};

Node no[max_size];

int main()
{
    int N;//×ÜÈËÊý
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>no[i].v>>no[i].t;
            no[i].v/=3.6;
            if(no[i].t<0)
                no[i].v=0.1;
            no[i].time=no[i].t+(3000.0/(no[i].v));
        }
        sort(no,no+N,cmp);
        int ans=ceil(no[0].time);
        cout<<ans<<endl;
    }
}
