#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int tmp;
    while(cin>>tmp){
        if(tmp<9)
            cout << "Oh NO!"<<endl;
        else
            cout << tmp-1<<endl;
    }
}
