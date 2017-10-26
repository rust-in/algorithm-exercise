#include <iostream>
#include <cmath>
using namespace std;
#define MAX 0xFFFFFF
int pot[505][505];

int main()
{
    ios_base::sync_with_stdio(false);
    int len,time;
    while(cin>>len>>time){
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                cin >> pot[i][j];
                if(pot[i][j]==-1)
                    pot[i][j]=MAX;
            }
        }

        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                for(int k=0;k<len;k++)
                    pot[j][k]=min(pot[j][k],pot[j][i]+pot[i][k]);

        int one,two;
        for(int i=0;i<time;i++){
            cin >> one >> two;
            if(pot[one-1][two-1]==MAX || one == two)
                cout << "jujue\n";
            else
                cout << pot[one-1][two-1] <<endl;
        }
    }
}
