#include<cstdio>
#include<cstring>
int n,m,ans;
int result[1010];//��¼V2�еĵ�ƥ��ĵ�ı��
bool state[1010];//��¼V2�е�ÿ�����Ƿ�������
bool data[1010][1010];//�ڽӾ���true�����б�����
bool Find(int a)
{
   for (int i=1;i<=n;i++)
       if (data[a][i]==1 && !state[i])
       {//����ڵ�i��a���ڲ���δ�����ҹ�
           state[i]=true;//���iΪ�Ѳ��ҹ�
           if (result[i]==0 || Find(result[i]))//�ҵ�δ��ƥ��ĵ�
                                            //�����������Ȼ�Ѿ���ƥ�䣬���ǿ����ҵ���������·��
            {
                result[i]=a;//��¼���ҳɹ���¼j
                return true;//���ز��ҳɹ�
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
            memset(state,0,sizeof(state));//����ϴ�����ʱ�ı��
            if (Find(i)) ans++;//�ӽڵ�i������չ
        }

        if(ans==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
