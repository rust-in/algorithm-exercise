#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
double res[101][101];
double C[101][101];
double p[101];

int main()
{
    int T;
    cin >> T;
    res[0][0] = 1;
    p[0] = 1;
    for(int i = 1; i <= 100; ++i)
        p[i] = p[i-1]/2;
    for(int i = 1; i <= 100; ++i){
        C[i][0] = C[i][i] = 1;
        int k = i/2;
        for(int j = 1; j <= k; ++j)
            C[i][i-j] = C[i][j] = C[i][j-1]*(i-j+1)/j;
    }
    int N, M, K;
    while(T--){
        cin >> N >> M >> K;
        for(int i = 1; i <= M; ++i)
            for(int j = 0; j <= N; ++j)
                res[i][j] = 0;
        double pp = p[K];
        for(int i = 1; i <= M; ++i){
            for(int j = 0; j <= N-K; ++j){
                double temp = res[i-1][j];
                if(temp)
                    for(int k = 0; k <= K; ++k)
                        res[i][j+k] += temp*C[K][k]*pp;
            }
            for(int j = N-K+1; j <= N; ++j){
                double temp = res[i-1][j];
                if(temp)
                    for(int k = N-K; k <= N; ++k)
                        res[i][k] += temp*C[K][k-N+K]*pp;
            }
        }
        res[M][0] = 0;
        for(int i = 1; i <= N; ++i)
            res[M][0] += i*res[M][i];
        cout << fixed << setprecision(3) << res[M][0] << endl;
    }
    return 0;
}
