#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

char s1[105];
char s2[105];
int L[105][105];
int len1,len2,len;

int main() {
    while(~scanf("%s%s",s1,s2)) {
        memset(L,0,sizeof(L));
        len1=strlen(s1);
        len2=strlen(s2);
        for(int i=0;i<=len1;i++) {
            for(int j=0;j<=len2;j++) {
                if(i==0 || j==0) L[i][j]=0;
                else if(s1[i-1]==s2[j-1] && s1[i-1]!='#' && s2[j-1]!='#') {
                    L[i][j]=L[i-1][j-1]+1;
                }
                else if((s1[i-1]=='?' && s2[j-1]!='#') || (s1[i-1]!='#' && s2[j-1]=='?')) {
                    L[i][j]=L[i-1][j-1]+1;
                }
                else {
                    if(L[i-1][j]>L[i][j-1]) {
                        L[i][j]=L[i-1][j];
                    }
                    else {
                        L[i][j]=L[i][j-1];
                    }
                }
//                printf("ans[%d][%d]=%d\n",i,j,L[i][j]);
            }
        }
        len=L[len1][len2];
        printf("%d\n",len);
    }
}
