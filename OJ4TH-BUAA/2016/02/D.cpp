#include <cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int key;
        bool flag = false;
        vector<int> one(n), two(n), arr3(n);
        vector<bool> res(n, false);

        for(int i = 0; i < n; i++){
            scanf("%d", &one[i]);
        }
        for(int i = 0; i < n; i++)
            scanf("%d", &two[i]);
        scanf("%d", &key);

        sort(one.begin(), one.end());
        sort(two.begin(), two.end());

        for(int i = 0; i < n; i++)
            arr3[i] = key - one[i];
        for(int i = 0; i < n; i++){
            if(binary_search(two.begin(), two.end(), arr3[i])){
                res[i] = true;
                flag = true;
            }
        }

        if(flag){
            double curr = -1e9;
            for(int i = 0; i < n; i++){
                if(res[i]){
                    if(one[i] > curr){
                        printf("%d %d\n", one[i], key-one[i]);
                        curr = one[i];
                    }
                }
            }
            printf("\n");
        }
        else{
            printf("OTZ\n\n");
        }
    }
    return 0;
}
