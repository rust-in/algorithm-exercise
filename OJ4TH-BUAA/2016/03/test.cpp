#include "stdafx.h"
#include<iostream>
#define N 100
using namespace std;
typedef int timeType;
// f1[j],f2[j]�ֱ�洢����ˮ��1,2վj������ʱ��
//j>=1
timeType f1[N],f2[N];
//l1[j],l2[j]�ֱ�洢����ˮ��1,2վj����һ����ˮ�ߵ�վj-1����
//j>=2
int l1[N],l2[N];
//�洢��Ʒ�������Сʱ��
timeType fx;
//lx�洢����Ǵ�������ˮ������
int lx;
//�洢ÿһ��վ��Ĵ���ʱ�� a1[j]��ʾ��ˮ��1��վ��j�ϵĴ���ʱ��
//j>=1
timeType a1[N],a2[N];
//�洢ת����ˮ����Ҫ��ʱ�� t1[j-1]��ʾ����ˮ��1վj-1ת������ˮ��2վj��Ҫ��ʱ��
//j>=2
timeType t1[N],t2[N];
//�洢�ֱ���Ʒ����ˮ��1,2��ʱ��
timeType e1,e2;
//�洢�ֱ���Ʒ����ˮ��1,2��ʱ��
timeType x1,x2;
//�洢���յ�·��
int line[N];
/*
void print_line(int *l1,int * l2,int line,int n)
{
 if(n==2)
 {
  if(line==1)
  {
   cout<<"line: "<<l1[n]<<"station: "<<n-1<<endl;
   line = l1[n];
  }
  else
  {
   cout<<"line: "<<l2[n]<<"station: "<<n-1<<endl;
   line = l2[n];
  }
 }
 else
 {
  print_line(l1,l2,line,n-1);
  cout<<
 }
}
*/
//���·�����Ӻ���ǰ��·�������뵽line�����У�Ȼ�����
void print_line(int *l1,int *l2,int *line,int lx,int n)
{
 int i = lx;
 line[n] = lx;
 int j;
 for(j=n;j>1;j--)
 {
  if(i==1)
  {
   i = l1[j];
   line[j-1] = i;
  }
  else
  {
   i = l2[j];
   line[j-1] = i;
  }
 }
 for(j=1;j<=n;j++)
  cout<<"line: "<<line[j]<<"��station: "<<j<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
 int cases;
 cout<<"�����밸��������"<<endl;
 cin>>cases;
 while(cases--)
 {
  //��ʼ��������
  memset(f1,0,sizeof(f1));
  memset(f2,0,sizeof(f2));
  memset(l1,0,sizeof(l1));
  memset(l2,0,sizeof(l2));
  memset(a1,0,sizeof(a1));
  memset(a2,0,sizeof(a2));
  memset(t1,0,sizeof(t1));
  memset(t2,0,sizeof(t2));
  memset(line,0,sizeof(line));
  lx=e1=e2=x1=x2=0;
  cout<<"��������ˮ��վ�������"<<endl;
  int n;
  cin>>n;
  int i;
  cout<<"����������ˮ��1��Ҫ���ĵ�ʱ�䣺"<<endl;
  cin>>e1;
  cout<<"����������ˮ��2��Ҫ���ĵ�ʱ�䣺"<<endl;
  cin>>e2;
  cout<<"����������ˮ��1��Ҫ���ĵ�ʱ�䣺"<<endl;
  cin>>x1;
  cout<<"����������ˮ��2��Ҫ���ĵ�ʱ�䣺"<<endl;
  cin>>x2;
  cout<<"��������ˮ��1ÿ��վ��Ĵ���ʱ�䣺"<<endl;
  for(i=1;i<=n;i++)
   cin>>a1[i];
  cout<<"��������ˮ��2ÿ��վ��Ĵ���ʱ�䣺"<<endl;
  for(i=1;i<=n;i++)
   cin>>a2[i];
  cout<<"��������ˮ��1վ��iת������ˮ��վ2վ��i+1����ʱ�䣺"<<endl;
  for(i=1;i<n;i++)
   cin>>t1[i];
  cout<<"��������ˮ��2վ��iת������ˮ��վ1վ��i+1����ʱ�䣺"<<endl;
  for(i=1;i<n;i++)
   cin>>t2[i];
  f1[1] = a1[1] + e1;
  f2[1] = a2[1] + e2;
  int j;
  for(j=2;j<=n;j++)
  {
   if(f1[j-1]+a1[j]<=f2[j-1]+t2[j-1]+a1[j])
   {
    f1[j] = f1[j-1] + a1[j];
    l1[j] = 1;
   }
   else
   {
    f1[j] = f2[j-1] + t2[j-1] + a1[j];
    l1[j] = 2;
   }
   if(f2[j-1]+a2[j]<=f1[j-1]+t1[j-1]+a2[j])
   {
    f2[j] = f2[j-1] + a2[j];
    l2[j] = 2;
   }
   else
   {
    f2[j] = f1[j-1] + t1[j-1] + a2[j];
    l2[j] = 1;
   }
  }
  if(f1[n]+x1<=f2[n]+x2)
  {
   fx = f1[n] + x1;
   lx = 1;
  }
  else
  {
   fx = f2[n] + x2;
   lx = 2;
  }
  cout<<"���·����"<<endl;
  print_line(l1,l2,line,lx,n);
  cout<<"��������ʱ��Ϊ��"<<fx<<endl;
 }
 system("pause");
 return 0;
}

