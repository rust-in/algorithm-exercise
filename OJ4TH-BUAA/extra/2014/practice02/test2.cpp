#include <bits/stdc++.h>
using namespace std;

int num[1000005];

// ����������������ֵ
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ��������
void insertSorting(int *arr, int from, int to) {

    int i, j, t;
    int sc;
    for (i = from + 1; i <= to; ++i) {
        sc = arr[i];
        j = i - 1;
        while(j >= from) {
            // �ҵ�һ��������arr[j] <= sc
            if (arr[j] > sc) {
                --j;
            } else {
                break;
            }
        }
        // ��arr[j + 1, i - 1]��ǰ�ƶ�һ��λ��
        // ��arr[j + 2, i]
        for (t = i; t > j; --t) {
            arr[t] = arr[t - 1];
        }
        arr[j + 1] = sc;
    }
}

// ��ָ��λ��pivot��Ԫ����Ϊ��Ԫ
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

// ����BFPRT ����kСԪ��
int BFPRT(int *arr, int from, int to, int ith) { //from=0,to=n-1,ith��1��ʼ
    // ��Ԫ��С��5����ʱ��ֱ�Ӳ��벢�ҷ���
    if(to - from + 1 <= 5) {
        insertSorting(arr, from, to);
        return arr[from + ith - 1];
    }

    int t = from - 1;
    // ��Ϊÿ5������Ŀ�ʼ�ͽ�����index
    int st, ed;
    // ������һ��Ԫ���ܽ������ѭ��, Ҳ���� to - from + 1 > 5
    for (st = from; (ed = st + 4) <= to; st += 5) {
        insertSorting(arr, st, ed);
        ++t;
        swap(arr + t, arr + st + 2);
    }

    // ���ĵ�����λ����λ�ã���������λ����ֵ
    int pivot = (from + t) >> 1;
    BFPRT(arr, from, t, pivot - from + 1);

    int m = partition(arr, from, to, pivot);
    // pivot Ϊ�ڼ�С
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
