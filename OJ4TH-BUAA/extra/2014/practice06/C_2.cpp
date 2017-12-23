#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1000000000
#define mod 1000000007
#define N 350000
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef unsigned long long ull;
const double pi = 3.141592653;
string s1,s2,s3,s4;
double rea[N],ina[N],reb[N],inb[N],ret[N],intt[N];
int i,len1,len2,lent,lenres,len;
int res[N>>1];
void Swap(double &x,double &y)
{
    double t = x;
    x = y;
    y = t;
}
int rev(int x,int len)
{
    int ans = 0,i;
    fo(i,1,len) {ans<<=1; ans|=x&1; x>>=1;}
    return ans;
}
void FFT(double *reA,double *inA,int n,int flag)
{
    int s,i,j,k; int lgn = log((double)n) / log((double)2);
    fo(i,0,n-1)//数组重排
    {
        j = rev(i,lgn);
        if (j > i) {Swap(reA[i],reA[j]); Swap(inA[i],inA[j]);}
    }

    fo(s,1,lgn)
    {
        int m = (1 << s);
        double reWm = cos(2*pi/m) , inWm = sin(2*pi/m);
        if (flag) inWm = -inWm;
        for (k = 0;k < n; k += m)
        {
            double reW = 1.0 , inW = 0.0;
            fo(j,0,m/2-1)
            {
                int tag = k + j + m / 2;
                double reT = reW * reA[tag] - inW * inA[tag];
                double inT = reW * inA[tag] + inW * reA[tag];
                double reU = reA[k+j] , inU = inA[k+j];
                reA[k+j] = reU + reT; inA[k+j] = inU + inT;
                reA[tag] = reU - reT; inA[tag] = inU - inT;
                double reWt = reW * reWm - inW * inWm;
                double inWt = reW * inWm + inW * reWm;
                reW = reWt; inW = inWt;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin>>s1>>s2){
        memset(res, 0 , sizeof(res));
        memset(rea, 0 , sizeof(rea));
        memset(ina, 0 , sizeof(ina));
        memset(reb, 0 , sizeof(reb));
        memset(inb, 0 , sizeof(inb));
        len1 = s1.length(); len2 = s2.length();
        lent = (len1 > len2 ? len1 : len2); len = 1;
        while (len < lent) len <<= 1; len <<= 1;
        fo(i,0,len-1)
        {
            if (i < len1) rea[i] = (double) s1[len1-i-1] - '0';
            if (i < len2) reb[i] = (double) s2[len2-i-1] - '0';
            ina[i] = inb[i] = 0.0;
        }
        FFT(rea,ina,len,0); FFT(reb,inb,len,0);//求出a、b的点值表示法
        fo(i,0,len-1)//求出c的点值表示法
        {
            //printf("%.5lf %.5lf\n",rea[i],ina[i]);
            double rec = rea[i] * reb[i] - ina[i] * inb[i];
            double inc = rea[i] * inb[i] + ina[i] * reb[i];
            rea[i] = rec; ina[i] = inc;
        }
        FFT(rea,ina,len,1);
        fo(i,0,len-1) {rea[i] /= len; ina[i] /= len;}

        fo(i,0,len-1) res[i] = (int)(rea[i] + 0.5);
        fo(i,0,len-1) res[i+1] += res[i] / 8/*10*/ , res[i] %= 8/*10*/;

        lenres = len1 + len2 + 2;
        while (res[lenres] == 0 && lenres > 0)
            lenres--;
        fd(i,lenres,0) printf("%d",res[i]); printf("\n");
    }
    return 0;
}
