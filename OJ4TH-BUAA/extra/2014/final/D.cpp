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



int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        while(m--){
            stack<int> myStack;
            bool flag = true;
            int tmp,up=0;

            for(int i=1;i<=n;i++){
                scanf("%d",&tmp);
                if(!flag) continue;
                if(tmp>up){
                    for(int j=up+1;j<tmp;j++)
                        myStack.push(j);
                    up=tmp;
                } else{
                    if(tmp==myStack.top())
                        myStack.pop();
                    else
                        flag=false;
                }
            }
            if(flag) printf("YES\n");
            else     printf("NO\n");
        }
    }
}
