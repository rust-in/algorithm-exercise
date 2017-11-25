#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char one[1005];
char two[1005];
int res[1005][1005];

int ans(char *one, char *two)
{
    int length1 = strlen(one), length2 = strlen(two);

    for (int i = 0; i <= length1; i++) res[i][0] = i;
    for (int j = 0; j <= length2; j++) res[0][j] = j;

    for (int i = 1; i <= length1; i++)
        for (int j = 1; j <= length2; j++) {
            if (one[i-1] == two[j-1]) {
                res[i][j] = res[i-1][j-1];
            } else {
                res[i][j] = min(res[i-1][j]+1, min(res[i][j-1]+1, res[i-1][j-1]+1));
            }
        }

    return res[length1][length2];
}

int main()
{
    while(~scanf("%s%s",one,two)){
        printf("%d\n",ans(one,two));
    }
}
