#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <map>
#include <queue>
using namespace std;
short int L[10005][10005];

// Returns length of the longest AP subnum in a given num
int lenghtOfLongestAP(int num[], int n){
    //if (n <= 2)  return n;

    // Create a table and initialize all values as 2. The value of
    // L[i][j] stores LLAP with num[i] and num[j] as first two
    // elements of AP. Only valid entries are the entries where j>i

//    memset(L,0,sizeof(L));
    int llap = 2;  // Initialize the result

    // Fill entries in last column as 2. There will always be
    // two elements in AP with last number of num[] as second
    // element in AP
    for (int i = 0; i < n; i++)
        for(int j=0;j<n;j++)
            L[i][j] = 2;

    // Consider every element as second element of AP
    for (int j=n-2; j>=1; j--){
        // finding for i and k for j
        int i = j-1, k = j+1;
        while (i >= 0 && k <= n-1)
        {
           if (num[i] + num[k] < 2*num[j])
                k++;

           // Before changing i, num L[i][j] as 2
           else if (num[i] + num[k] > 2*num[j]){
//                L[i][j] = 2;
                i--;
           }

           else{
               // Found i and k for j, LLAP with i and j as first two
               // elements is equal to LLAP with j and k as first two
               // elements plus 1. L[j][k] must have been filled
               // before as we run the loop from right side
               L[i][j] = L[j][k] + 1;

               // Update overall LLAP, if needed
               if(L[i][j]>llap) llap=L[i][j];
//               llap = max(llap, L[i][j]);

               // Change i and k to fill more L[i][j] values for
               // current j
               i--; k++;
           }
        }

        // If the loop was stopped due to k becoming more than
        // n-1, num the remaining entties in column j as 2
//        while (i >= 0)
//        {
//            L[i][j] = 2;
//            i--;
//        }
    }
    return llap;
}

#define MAXL 10005
int finding(short a[], int n)
{
    short dp[n+5][n+5];
    for(int i=0;i<n+5;i++)
        for(int j=0;j<n+5;j++)
            dp[i][j]=0;
    int i, j;
    for(i = 1; i < n; i++) {
        int p = 0;
        for(j = 0; j < i; j++) {
            dp[j][i] = 2;
            while(p < j && (a[p] + a[i]) < 2 * a[j])
                p++;
            if(p < j && (a[p] + a[i]) == 2 * a[j])
                dp[j][i] = max(dp[j][i], (short)(dp[p][j] + 1));
        }
    }
    short ans = 0;
    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++)
            ans = max(ans, dp[j][i]);
    return (int)ans;
}

int num[10005];

int main()
{
    int len;
    while(~scanf("%d",&len)){
        for(int i=0;i<len;i++)
            scanf("%d",&num[i]);
        sort(num,num+len);
//        for(int i=0;i<=len;i++)
//            printf("%ld ",num[i]);
//        printf("\n");
        printf("%d\n",lenghtOfLongestAP(num,len));
    }

    return 0;
}
