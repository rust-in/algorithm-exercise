#include<cstdio>
#include<cstring>
const int n1=1005,n2=1005;  //����ͼ��x��y�е����Ŀ
int n,m,ans;
int result[1010];//��¼V2�еĵ�ƥ��ĵ�ı��
bool state[1010];//��¼V2�е�ÿ�����Ƿ�������
bool data[1010][1010];//�ڽӾ���true�����б�����
bool Find(int a)
{
   for (int i=1;i<=n2;i++)
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
           memset(state,0,sizeof(state));//����ϴ�����ʱ�ı��
           if (Find(i)) ans++;//�ӽڵ�i������չ
       }
       printf("%d\n",ans);
    }
    return 0;
}
