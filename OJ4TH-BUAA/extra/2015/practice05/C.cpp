#include <iostream>

using namespace std;

//���ܼ���
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

//����������
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

                //����ﵽ�߽磬ʵ�ʴ���Ϊλ����31������̯����Ϊ0
                if (num + 1LL >= lim) cout << "31 0\n", num = 0;
                else
                    //δ�ﵽ���ۣ�ʵ�ʴ���Ϊ����������̯����Ϊ������+�Ʋ�
                    cout << getAct(num) << " " << getAct(num) + getP(num + 1LL) - getP(num) << "\n",
                            num++;
            }
            cout << "Sum: " << num << "\n";
        }
    }
}
