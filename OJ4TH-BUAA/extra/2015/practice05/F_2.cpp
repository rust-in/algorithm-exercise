#include<cstdio>
#include<cstring>
#define MaxSize 1005
int n,m;  //二分图中x和y中点的数目
int A[MaxSize], B[MaxSize]; //存放AB数组（结构体）
int ans;
int result[MaxSize];//记录V2中的点匹配的点的编号
bool state[MaxSize];//记录V2中的每个点是否被搜索过
bool data[MaxSize][MaxSize];//邻接矩阵true代表有边相连

bool Find(int a)
{
   for (int i=1;i<MaxSize;i++)
       if (data[a][i]==true && !state[i])
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

int match()
{
    ans=0;
    memset(result,0,sizeof(result));
    for (int i=1;i<MaxSize;i++){
       memset(state,0,sizeof(state));//清空上次搜索时的标记
       if (Find(i)) ans++;//从节点i尝试扩展
   }
   return ans;
}

int main()
{
    while(~scanf("%d",&n))
    {
        int a,b;
        memset(data,0,sizeof(data));
        for (int i=1;i<=n;i++){
            scanf("%d %d",&a,&b);
            data[a][b]=true;
        }
        printf("%d\n",match());
    }
    return 0;
}
