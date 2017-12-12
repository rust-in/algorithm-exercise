#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    string name;
    int len;

    cin >> len; cin >> name;
    for(int i=0;i<len;i++){
        if(name[i]=='A'){
            if(name.substr(i,7)=="AlvinZH")
                cout << "hg, shg, awsl!\n";
        }
        else if(name[i]=='B'){
            if(name.substr(i,6)=="Bamboo")
                cout << "this is 51's father\n";
            else if(name.substr(i,4)=="BCPC")
                cout << "I want to join in!\n";
        }
        else if(name[i]=='C'){
            if(name.substr(i,11)=="ConnorZhong")
                cout << "I am so weak\n";
        }
        else if(name[i]=='M'){
            if(name.substr(i,10)=="ModricWang")
                cout << "1080Ti!, wyr, silver!!!\n";
        }
    }
}
