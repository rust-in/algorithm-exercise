#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int abc[805][805];
struct node
{
    int x;
    int y;
}pip[505];

bool cmp(node a, node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}


int main()
{
    int len;
    while(~scanf("%d",&len)){
        int x,y;    memset(abc,0,sizeof(abc));
        for(int i=0;i<len;i++){
            scanf("%d%d",&x,&y);
            x+=300; y+=300;
            pip[i].x=x;    pip[i].y=y;
            abc[x][y]=1;
        }
        sort(pip,pip+len,cmp);
        int sum=0;
        for(int i=0;i<len;i++)
            for(int j=i+1;j<len;j++){
                int abx = pip[j].x - pip[i].x;
                int aby = pip[j].y - pip[i].y;
                if(aby>0)
                    if(abc[pip[i].x+aby][pip[i].y-abx]&&abc[pip[j].x+aby][pip[j].y-abx])
                        sum++;
                else{
                    aby*=-1;
                    if(abc[pip[i].x+aby][pip[i].y+abx]&&abc[pip[j].x+aby][pip[j].y+abx])
                        sum++;
                }
            }
        cout << sum/2 << endl;
    }
}
