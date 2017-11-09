#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MaxVal = 0xfffffff;

int n;
//���������ڵ��������ĸ���
double p[25];
double q[25];

int root[25 + 1][25 + 1]; //��¼���ڵ�
double w[25 + 2][25 + 2]; //���������ܺ�
double e[25 + 2][25 + 2]; //������������
/*
 * p�Ǵ�Źؼ��ֽڵ���ʵ�����[1,n]��q�Ǵ��α�ؼ��ֽڵ�(Ҷ�ӽڵ�)���ָ��ʵ�����[0,n]
 * n�ǽڵ����
 * e[i,j]�Ǵ�Ű����ؼ���Ki~Kj�����Ŷ��������һ���������������ۣ�����Ҫ����e[n+1,n]��q[n]��e[1,0]q[0]�����Է�Χ��[0,n+1]
 * w[i,j]�Ǵ��Ki~Kj�ĸ��ʺ�,w[i,j]=w[i,r-1]+p[r]+w[r+1,j]
 * root[i,j]�Ǵ�Ű���Ki~Kj�Ĺؼ��ֵ���������������£�root�ڵ���±�
 */
void optimal_Bst(double* p, double* q, int n) {
    memset(e,0,sizeof(e));
    memset(w,0,sizeof(w));
    //���ȴ���w[i,j]��e[i,j]��i=j+1������������������q[i-1]
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    //Ȼ������L��1��n��ѭ��

    int l = 0; //����ki~kj�ĳ���
    int j = 0; //�������һ��Ԫ�ص��±�ֵj
    int i = 0; //������ʼ��һ��Ԫ�ص��±�ֵi

    int r = 0; //����root�ڵ���±�

    double tmp = 0; //����Ҫ�洢e����Ԫ�ؼ������ʱ���������Ҳ��double���͵�

    for (l = 1; l <= n; l++) {

        //��iΪ���ѭ�����������ڳ�����L��i���Ϊn-l+1����j-i+1=L��j=L+i-1
        for (i = 1; i <= n - l + 1; i++) {
            j = l + i - 1;

            //�ȳ�ʼ��e[i][j]��w[i][j]
            e[i][j] = MaxVal;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (r = i; r <= j; r++) {
                //��ʽ��e[i][j] = e[i][r - 1] + e[r + 1][j] + w[i][j];
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
 * �Ż���
 */
void optimal_Bst2(double* p, double* q, int n) {
    //���ȴ���w[i,j]��e[i,j]��i=j+1������������������q[i-1]
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    //Ȼ������L��1��n��ѭ��

    int l = 0; //����ki~kj�ĳ���
    int j = 0; //�������һ��Ԫ�ص��±�ֵj
    int i = 0; //������ʼ��һ��Ԫ�ص��±�ֵi

    int r = 0; //����root�ڵ���±�

    double tmp = 0; //����Ҫ�洢e����Ԫ�ؼ������ʱ���������Ҳ��double���͵�

    for (l = 1; l <= n; l++) {

        //��iΪ���ѭ�����������ڳ�����L��i���Ϊn-l+1����j-i+1=L��j=L+i-1
        for (i = 1; i <= n - l + 1; i++) {
            j = l + i - 1;

            e[i][j] = MaxVal;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            if (i == j) {
                root[i][j] = i;
                e[i][j] = p[i] + 2*q[i - 1] + 2*q[i];

            } else {
                //�ȳ�ʼ��e[i][j]��w[i][j]

                for (r = root[i][j - 1]; r <= root[i + 1][j]; r++) {
                    //��ʽ��e[i][j] = e[i][r - 1] + e[r + 1][j] + w[i][j];
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
        cout << "�����Ϊ��k" << root_node << endl;
        root_flag = false;
        print_optimal_Bst(i, root_node - 1, root_node, root_flag);
        print_optimal_Bst(root_node + 1, j, root_node, root_flag);
        return;
    }

    if (i > j + 1) {
        return;
    } else if (i == j + 1) {
        if (j < r) {
            cout << "d" << j << "��" << "k" << r << "������" << endl;
        } else {
            cout << "d" << j << "��" << "k" << r << "���Һ���" << endl;
        }
        return; //����Ӹ�return����Ϊ����ѭ����i==j+1��ʱ���Ѿ���ͷ�ˣ������ٵݹ��ˣ���ʱ�����ں����root_node��
    } else {
        if (root_node < r) {
            cout << "k" << root_node << "��" << "k" << r << "������" << endl;
        } else {
            cout << "k" << root_node << "��" << "k" << r << "���Һ���" << endl;
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
