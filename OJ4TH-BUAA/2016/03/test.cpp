#include "stdafx.h"
#include<iostream>
#define N 100
using namespace std;
typedef int timeType;
// f1[j],f2[j]分别存储到流水线1,2站j的最少时间
//j>=1
timeType f1[N],f2[N];
//l1[j],l2[j]分别存储到流水线1,2站j是哪一条流水线的站j-1来的
//j>=2
int l1[N],l2[N];
//存储物品处理的最小时间
timeType fx;
//lx存储最后是从哪条流水线流出
int lx;
//存储每一个站点的处理时间 a1[j]表示流水线1的站点j上的处理时间
//j>=1
timeType a1[N],a2[N];
//存储转换流水线需要的时间 t1[j-1]表示从流水线1站j-1转换到流水线2站j需要的时间
//j>=2
timeType t1[N],t2[N];
//存储分别物品上流水线1,2的时间
timeType e1,e2;
//存储分别物品下流水线1,2的时间
timeType x1,x2;
//存储最终的路径
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
//输出路径，从后往前把路径倒存入到line数组中，然后输出
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
  cout<<"line: "<<line[j]<<"，station: "<<j<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
 int cases;
 cout<<"请输入案例个数："<<endl;
 cin>>cases;
 while(cases--)
 {
  //初始化各变量
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
  cout<<"请输入流水线站点个数："<<endl;
  int n;
  cin>>n;
  int i;
  cout<<"请输入上流水线1需要消耗的时间："<<endl;
  cin>>e1;
  cout<<"请输入上流水线2需要消耗的时间："<<endl;
  cin>>e2;
  cout<<"请输入下流水线1需要消耗的时间："<<endl;
  cin>>x1;
  cout<<"请输入下流水线2需要消耗的时间："<<endl;
  cin>>x2;
  cout<<"请输入流水线1每个站点的处理时间："<<endl;
  for(i=1;i<=n;i++)
   cin>>a1[i];
  cout<<"请输入流水线2每个站点的处理时间："<<endl;
  for(i=1;i<=n;i++)
   cin>>a2[i];
  cout<<"请输入流水线1站点i转换到流水线站2站点i+1消耗时间："<<endl;
  for(i=1;i<n;i++)
   cin>>t1[i];
  cout<<"请输入流水线2站点i转换到流水线站1站点i+1消耗时间："<<endl;
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
  cout<<"输出路径："<<endl;
  print_line(l1,l2,line,lx,n);
  cout<<"最少消耗时间为："<<fx<<endl;
 }
 system("pause");
 return 0;
}

