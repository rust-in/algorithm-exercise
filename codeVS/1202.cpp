#include <iostream>
using namespace std;

int main()
{
    int n;  cin >> n;
    int sum = 0,a;
    while(n--){
        cin >> a;
        sum += a;
    }
    cout << sum;
}
