#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string name[1000];
    int i=0;
    while(cin >> name[i])   i++;

    for(int j=i-1;j>=0;j--)
        cout << name[j] << ' ';
}
