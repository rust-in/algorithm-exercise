#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
struct Point{string name;double x,y,z;};
const double PI=3.141592653;
bool cmp(Point a,Point b)
{
    if(a.z!=b.z)return a.z<b.z;
    else return a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;
}
int main()
{
    ios::sync_with_stdio(0);
    int n;
    while(~scanf("%d",&n))
    {
        Point a[n+1];
        for(int i=0;i<n;++i)
        {
            cin>>a[i].name>>a[i].x>>a[i].y;
            if(a[i].x!=0)
            {
                a[i].z=atan(a[i].y/a[i].x)/PI;
                if(a[i].x<0)a[i].z++;
            }
            else
            {
                if(a[i].y>0)a[i].z=0.5;
                if(a[i].z<0)a[i].z=1.5;
                if(a[i].z==0)a[i].z=-1;
            }
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;++i)cout<<a[i].name<<endl;
        printf("\n");
        //cout<<endl;
    }
}
