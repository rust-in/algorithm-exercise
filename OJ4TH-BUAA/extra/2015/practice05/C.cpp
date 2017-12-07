#include <iostream>

using namespace std;

//势能计算
long long getP(long long x) {
    long long cnt = 0LL;
    while (x > 0LL) {
        if (x & 1LL) cnt++;
        x >>= 1LL;
    }
    return cnt;
}

long long k, bit, num, op, n, T;
long long lim;

//操作数计算
long long getAct(long long x) {
    long long cnt = 1LL;
    while (x > 0LL) {
        if (x & 1LL) cnt++;
        else break;
        x >>= 1LL;
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    T = 0;
    while (cin >> n >> num) {
        k = 31LL;
        lim = (1LL << k);
        for (int T = 0; T < n; T++) {
            cout << "Case " << T + 1 << ": \n";
            cin >> op;
            while (op--) {

                //如果达到边界，实际代价为位数（31），均摊代价为0
                if (num + 1LL >= lim) cout << "31 0\n", num = 0;
                else
                    //未达到代价，实际代价为操作数，均摊代价为操作数+势差
                    cout << getAct(num) << " " << getAct(num) + getP(num + 1LL) - getP(num) << "\n",
                            num++;
            }
            cout << "Sum: " << num << "\n";
        }
    }
}
