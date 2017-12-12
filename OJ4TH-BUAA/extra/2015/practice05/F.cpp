#include<cstdio>
#include<cstring>
const int n1=1005,n2=1005;  //二分图中x和y中点的数目
int n,m,ans;
int result[1010];//记录V2中的点匹配的点的编号
bool state[1010];//记录V2中的每个点是否被搜索过
bool data[1010][1010];//邻接矩阵true代表有边相连
bool Find(int a)
{
   for (int i=1;i<=n2;i++)
       if (data[a][i]==1 && !state[i])
       {//如果节点i与a相邻并且未被查找过
           state[i]=true;//标记i为已查找过
           if (result[i]==0 || Find(result[i]))//找到未被匹配的点
                                            //或者这个点虽然已经被匹配，但是可以找到它的增广路径
            {
                result[i]=a;//记录查找成功记录j
                return true;//返回查找成功
           }
       }
   return false;
}
int main()
{
    while(~scanf("%d",&n))
    {
       memset(data,0,sizeof(data));
       memset(result,0,sizeof(result));
       ans=0;
       for (int i=1;i<=n;i++)
       {
           int u,v;
           scanf("%d%d",&u,&v);
           data[u][v]=true;
       }
       for (int i=1;i<=n1;i++)
       {
           memset(state,0,sizeof(state));//清空上次搜索时的标记
           if (Find(i)) ans++;//从节点i尝试扩展
       }
       printf("%d\n",ans);
    }
    return 0;
}
