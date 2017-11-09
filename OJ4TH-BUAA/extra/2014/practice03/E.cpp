#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MaxVal = 0xfffffff;

int n;
//搜索到根节点和虚拟键的概率
double p[25];
double q[25];

int root[25 + 1][25 + 1]; //记录根节点
double w[25 + 2][25 + 2]; //子树概率总和
double e[25 + 2][25 + 2]; //子树期望代价
/*
 * p是存放关键字节点概率的数组[1,n]，q是存放伪关键字节点(叶子节点)出现概率的数组[0,n]
 * n是节点个数
 * e[i,j]是存放包含关键字Ki~Kj的最优二叉书进行一次搜索的期望代价，由于要包括e[n+1,n]的q[n]和e[1,0]q[0]，所以范围是[0,n+1]
 * w[i,j]是存放Ki~Kj的概率和,w[i,j]=w[i,r-1]+p[r]+w[r+1,j]
 * root[i,j]是存放包含Ki~Kj的关键字的子树，最优情况下，root节点的下标
 */
void optimal_Bst(double* p, double* q, int n) {
    memset(e,0,sizeof(e));
    memset(w,0,sizeof(w));
    //首先处理w[i,j]和e[i,j]中i=j+1的情况，这种情况都是q[i-1]
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    //然后处理长度L从1到n的循环

    int l = 0; //代表ki~kj的长度
    int j = 0; //代表最后一个元素的下标值j
    int i = 0; //代表起始的一个元素的下标值i

    int r = 0; //代表root节点的下标

    double tmp = 0; //这里要存储e数组元素计算的临时结果，所以也是double类型的

    for (l = 1; l <= n; l++) {

        //以i为外层循环，这里由于长度是L，i最大为n-l+1，而j-i+1=L，j=L+i-1
        for (i = 1; i <= n - l + 1; i++) {
            j = l + i - 1;

            //先初始化e[i][j]和w[i][j]
            e[i][j] = MaxVal;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (r = i; r <= j; r++) {
                //公式：e[i][j] = e[i][r - 1] + e[r + 1][j] + w[i][j];
                tmp = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (tmp < e[i][j]) {
                    e[i][j] = tmp;
                    root[i][j] = r;
                }
            }
        }
    }
}

/*
 * 优化版
 */
void optimal_Bst2(double* p, double* q, int n) {
    //首先处理w[i,j]和e[i,j]中i=j+1的情况，这种情况都是q[i-1]
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    //然后处理长度L从1到n的循环

    int l = 0; //代表ki~kj的长度
    int j = 0; //代表最后一个元素的下标值j
    int i = 0; //代表起始的一个元素的下标值i

    int r = 0; //代表root节点的下标

    double tmp = 0; //这里要存储e数组元素计算的临时结果，所以也是double类型的

    for (l = 1; l <= n; l++) {

        //以i为外层循环，这里由于长度是L，i最大为n-l+1，而j-i+1=L，j=L+i-1
        for (i = 1; i <= n - l + 1; i++) {
            j = l + i - 1;

            e[i][j] = MaxVal;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            if (i == j) {
                root[i][j] = i;
                e[i][j] = p[i] + 2*q[i - 1] + 2*q[i];

            } else {
                //先初始化e[i][j]和w[i][j]

                for (r = root[i][j - 1]; r <= root[i + 1][j]; r++) {
                    //公式：e[i][j] = e[i][r - 1] + e[r + 1][j] + w[i][j];
                    tmp = e[i][r - 1] + e[r + 1][j] + w[i][j];
                    if (tmp < e[i][j]) {
                        e[i][j] = tmp;
                        root[i][j] = r;
                    }
                }
            }
        }
    }
}

void print_optimal_Bst(int i, int j, int r, bool root_flag) {
    int root_node = root[i][j];
    if (root_flag) {
        cout << "根结点为：k" << root_node << endl;
        root_flag = false;
        print_optimal_Bst(i, root_node - 1, root_node, root_flag);
        print_optimal_Bst(root_node + 1, j, root_node, root_flag);
        return;
    }

    if (i > j + 1) {
        return;
    } else if (i == j + 1) {
        if (j < r) {
            cout << "d" << j << "是" << "k" << r << "的左孩子" << endl;
        } else {
            cout << "d" << j << "是" << "k" << r << "的右孩子" << endl;
        }
        return; //这里加个return是因为，当循环到i==j+1的时候，已经到头了，不能再递归了，此时不存在合理的root_node了
    } else {
        if (root_node < r) {
            cout << "k" << root_node << "是" << "k" << r << "的左孩子" << endl;
        } else {
            cout << "k" << root_node << "是" << "k" << r << "的右孩子" << endl;
        }
    }
    print_optimal_Bst(i, root_node - 1, root_node, root_flag);
    print_optimal_Bst(root_node + 1, j, root_node, root_flag);
}

void optimal_bst3(double *p, double *q,int n)
{
//    double e[25][25], w[25][25];
    int r[25][25];
    //int r[MAX][MAX];
    int i, j, k, len;
    double tmp;

    //initialize
    memset(e, 0, sizeof(e));
    memset(w, 0, sizeof(w));
    memset(r, 0, sizeof(r));
    for(i=1; i<=n+1; i++)
    {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }

    //bottom to up
    for(len=1; len<=n; len++)
    {
        for(i=1; i<=n-len+1; i++)
        {
            j=i+len-1;
            w[i][j] = w[i][j-1]+p[j]+q[j];
            e[i][j] = MaxVal;
            r[i][j] = i;
            for(k=i; k<=j; k++)
            {
                tmp = e[i][k-1]+e[k+1][j]+w[i][j];
                if(e[i][j] > tmp)
                {
                    e[i][j] = tmp;
                    r[i][j] = k;
                }
            }
        }
    }
  printf("%.3lf\n",e[1][n]);
//  printf("w[1][n] = %lf\n",w[1][n]);

    //print result
    //print(1, n);

}
int main()
{
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++)   scanf("%lf",&p[i]);
        for(int i=0;i<=n;i++)   scanf("%lf",&q[i]);
        optimal_bst3(p,q,n);
    }
}
