#include<cstdio>
#include<cstring>
int n,m,ans;
int result[1010];//记录V2中的点匹配的点的编号
bool state[1010];//记录V2中的每个点是否被搜索过
bool data[1010][1010];//邻接矩阵true代表有边相连
bool Find(int a)
{
   for (int i=1;i<=n;i++)
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

struct mine{
    int A;
    int L;
    int P;
} one[1005];

struct yours{
    int A;
    int L;
} two[1005];

int main()
{
    while(~scanf("%d",&n))
    {
        memset(data,0,sizeof(data));
        memset(result,0,sizeof(result));
        ans=0;

        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&one[i].A,&one[i].L,&one[i].P);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&two[i].A,&two[i].L);

        for (int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(one[i].P==3)
                    data[i][j]=true;
                else if(one[i].P==2 && two[j].A < one[i].L)
                    data[i][j]=true;
                else if(one[i].P==1 && two[j].L <= one[i].A)
                    data[i][j]=true;
                else if(one[i].P==0 && two[j].L <= one[i].A && two[j].A < one[i].L)
                    data[i][j]=true;
            }
        }

        for (int i=1;i<=n;i++){
            memset(state,0,sizeof(state));//清空上次搜索时的标记
            if (Find(i)) ans++;//从节点i尝试扩展
        }

        if(ans==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
