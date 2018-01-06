#include<cstdio>
#include<cstring>
#define MaxSize 1005
int n,m;  //����ͼ��x��y�е����Ŀ
int A[MaxSize], B[MaxSize]; //���AB���飨�ṹ�壩
int ans;
int result[MaxSize];//��¼V2�еĵ�ƥ��ĵ�ı��
bool state[MaxSize];//��¼V2�е�ÿ�����Ƿ�������
bool data[MaxSize][MaxSize];//�ڽӾ���true�����б�����

bool Find(int a)
{
   for (int i=1;i<MaxSize;i++)
       if (data[a][i]==true && !state[i])
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

int match()
{
    ans=0;
    memset(result,0,sizeof(result));
    for (int i=1;i<MaxSize;i++){
       memset(state,0,sizeof(state));//����ϴ�����ʱ�ı��
       if (Find(i)) ans++;//�ӽڵ�i������չ
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
