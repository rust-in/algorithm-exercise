#include <cstdio>
#include <algorithm>
#define max_size 10010
using namespace std;
int order[max_size];

struct node{
    int start,ending;
    int id;
};

node act[max_size];

bool cmp(node a,node b)
{
    return a.ending<b.ending;
};

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
           {
               scanf("%d%d",&act[i].start,&act[i].ending);
                act[i].id=i+1;
           }
        sort(act,act+n,cmp);
        order[0]=0;
        int number=1;
        for(int i=1;i<n;i++)
        {
            if(act[i].start>=act[order[number-1]].ending)
                order[number++]=i;
        }
        printf("%d\n", number);
    }
}
