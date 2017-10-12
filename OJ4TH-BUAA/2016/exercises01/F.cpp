#include <iostream>
#include <iomanip>
using namespace std;

int one[100005],two[100005];
int len,pre;

bool isBig(double num)
{
    double sum=0;
    for(int i=0;i<len;i++)
        if(one[i]*num>two[i])
            sum+=(one[i]*num-two[i]);

    return sum>(num*pre);
}

int main()
{
    while(cin>>len>>pre){
        long sum=0;
        for(int i=0;i<len;i++){
            cin>>one[i]>>two[i];
            sum+=one[i];
        }
        if(sum<=pre)
            cout << "Great Robot!" << endl;
        else{
            double mid=0,l=0,r=10000000000;

            for(int i=0;i<50;i++){
                mid = (l+r)/2;
                isBig(mid)?r=mid:l=mid;
            }
            cout << setprecision(3) << fixed << mid << endl;
        }
    }
}
