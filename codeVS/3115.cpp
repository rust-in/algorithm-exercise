#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
char stra[10001],strb[10001];
int c[10001],d[10001];

int main()
{
	cin>>stra>>strb;
	int lena=0,i=0,lenb=0,flag=1;
	lena=strlen(stra);
	lenb=strlen(strb);
	if(lena<lenb) flag=0;
	else if(lena==lenb)
	{
		while(stra[i]==strb[i]) i++;
		if(i==lena) {cout<<"0"; return 0;}
		if(stra[i]<strb[i]) flag=0;
	}
	if(flag==0)
	{
		cout<<"-";
		for(i=0;i<lena;i++) d[i]=stra[lena-i-1]-'0';
		for(i=0;i<lenb;i++) c[i]=strb[lenb-i-1]-'0';
	}
	else
	{
		for(i=0;i<lena;i++) c[i]=stra[lena-i-1]-'0';
		for(i=0;i<lenb;i++) d[i]=strb[lenb-i-1]-'0';
	}
	for(i=0;i<10000;i++) c[i]=c[i]-d[i];
	for(i=0;i<10000;i++)
		if(c[i]<0) {c[i]+=10; c[i+1]-=1;}
	i=10000;
	while(c[i]==0) i--;
	while(i>=0) cout<<c[i--];
	return 0;
}
