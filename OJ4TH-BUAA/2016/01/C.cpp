#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long cross[55];
    long ncross[55];
    ncross[0]=cross[0]=1;
    ncross[1]=cross[1]=2;
    ncross[2]=3;
    cross[2]=4; //¿ç¹ý

    int len;
    while(~scanf("%d",&len)){
        for(int i=3;i<len;i++){
            ncross[i]=cross[i-1]+cross[i-2];
            cross[i]=ncross[i]+ncross[i-3];
        }

        cout << cross[len-1] << endl;
    }
}
