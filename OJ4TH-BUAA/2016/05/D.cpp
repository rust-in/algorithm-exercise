#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

double expec[100005];

int main()
{
    int len;    scanf("%d",&len);
    double num, p;
    while(len--){
        scanf("%lf%lf",&num,&p);
        double temp = num*(num-1)/2, _temp;
        expec[1]=0;
        for(int i=2;i<=num;i++){ //计算班级中存在了第i个学霸的期望
            _temp = (i-1)*(num-i+1);
            expec[i] = temp/(_temp*p) + expec[i-1];
        }
        printf("%.3lf\n",expec[(int)num]);
    }
}
