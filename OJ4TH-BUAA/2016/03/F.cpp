#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> abc;
    int tmp;
    cin >> tmp;
    abc.push(tmp);
    int fin=0;
    for(int i=1;i<n;i++){
        cin>>tmp;
        if(tmp<=abc.top())
            abc.push(tmp),fin=max(fin,int(abc.size()));
        else{
            while(!abc.empty()){
                abc.pop();
                if(abc.top()>=tmp)
                    break;
            }
            abc.push(tmp);
        }
    }
    cout << fin << endl;
}
