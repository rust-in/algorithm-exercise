#include <bits/stdc++.h>
using namespace std;

int num[1000005];

// 交换两个整数的数值
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 插入排序
void insertSorting(int *arr, int from, int to) {

    int i, j, t;
    int sc;
    for (i = from + 1; i <= to; ++i) {
        sc = arr[i];
        j = i - 1;
        while(j >= from) {
            // 找到一个不满足arr[j] <= sc
            if (arr[j] > sc) {
                --j;
            } else {
                break;
            }
        }
        // 将arr[j + 1, i - 1]向前移动一个位置
        // 即arr[j + 2, i]
        for (t = i; t > j; --t) {
            arr[t] = arr[t - 1];
        }
        arr[j + 1] = sc;
    }
}

// 讲指定位置pivot的元素作为主元
int partition(int *arr, int from, int to, int pivot) {
    int sc = arr[pivot];
    swap(arr + from, arr + pivot);
    int low = from;
    int high = to;
    while (low < high) {
        while (low < high && sc <= arr[high]) {
            --high;
        }
        arr[low] = arr[high];

        while (low < high && sc >= arr[low]) {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = sc;
    return high;
}

// 利用BFPRT 求解第k小元素
int BFPRT(int *arr, int from, int to, int ith) { //from=0,to=n-1,ith从1开始
    // 当元素小于5个的时候直接插入并且返回
    if(to - from + 1 <= 5) {
        insertSorting(arr, from, to);
        return arr[from + ith - 1];
    }

    int t = from - 1;
    // 作为每5个数组的开始和结束的index
    int st, ed;
    // 至少有一组元素能进入这个循环, 也就是 to - from + 1 > 5
    for (st = from; (ed = st + 4) <= to; st += 5) {
        insertSorting(arr, st, ed);
        ++t;
        swap(arr + t, arr + st + 2);
    }

    // 关心的是中位数的位置，而不是中位数的值
    int pivot = (from + t) >> 1;
    BFPRT(arr, from, t, pivot - from + 1);

    int m = partition(arr, from, to, pivot);
    // pivot 为第几小
    int cur = m - from + 1;

    int res;
    if (cur == ith) {
        res = arr[m];
    } else if (cur < ith) {
        res = BFPRT(arr, m + 1, to, ith - cur);
    } else {
        res = BFPRT(arr, from, m - 1, ith);
    }
    return res;
}

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        printf("%d\n",BFPRT(num,0,n-1,n-k+1));
    }
}
