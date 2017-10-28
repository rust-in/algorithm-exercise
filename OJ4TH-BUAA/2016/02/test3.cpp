#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    float num[] = {0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330, 360, 390, 420, 450, 480, 510, 540, 570, 600, 630};
    float ted[] = {70.6, 69.1, 66.7, 64.1, 61.9, 59.6, 57.5, 55.5, 53.7, 52.0, 50.4, 49.0, 47.5, 46.2, 45.1, 43.9, 42.8, 41.8, 40.8, 39.8, 39.0, 38.1};

    int len = sizeof(num)/sizeof(num[0]);

    cout << len << endl;

    float sumx=0,sumy=0,doux=0,douy=0,douxy=0;
    for(int i=0;i<len;i++){
        sumx+=num[i];
        sumy+=ted[i];
        doux+=pow(num[i],2);
        douy+=pow(ted[i],2);
        douxy+=num[i]*ted[i];
    }

    sumx/= len; sumy/=len;  doux/=len;  douy/=len;  douxy/=len;
    cout << sumx << " " << sumy<<endl;
    cout << doux << " " << douy<<endl;
    cout << douxy << endl;

    float b = (sumx*sumy-douxy)/(doux-douy);
    float r = (douxy - sumx*sumy)/sqrt((doux - pow(sumx,2))*(douy - pow(sumy, 2)));

    cout << b << " " <<r << endl;

    float res = b*sqrt((1/(r*r)-1)/(len-2));
    cout << res << endl;
}
