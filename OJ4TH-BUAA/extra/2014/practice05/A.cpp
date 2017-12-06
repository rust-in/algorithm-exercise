#include <iostream>
using namespace std;

int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int a,b;
    while(cin >> a >> b){
        if(a==12){
            if (b<12){
                cout << "It will come in " << 12 - b << " day(s) ORZ\n";
            } else if(b==12){
                cout << "Oh my god! It's today!!\n";
            } else{
                cout << "Lucky , it has passed!\n";
            }
        } else{
            int sum=12;
            for(int i=a+1;i<=11;i++){
                sum += mon[i];
            }
            sum += mon[a]-b;
            cout << "It will come in " << sum << " day(s) ORZ\n";
        }
    }
}
