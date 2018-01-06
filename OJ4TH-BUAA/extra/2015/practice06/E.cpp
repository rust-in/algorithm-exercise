#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

struct point {
	double x, y;
};

/*
PointSet[]：输入的点集
ch[]：输出的凸包上的点集，按照逆时针方向排列
n：PointSet中的点的数目
len：输出的凸包上的点的个数
*/
const int maxN = 1000;
point PointSet[maxN];
point ch[maxN];
int n;
int len;

//小于0,说明向量p0p1的极角大于p0p2的极角
double multiply(point p1, point p2, point p0) {
	return ((p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y));
}

double distant(point p1, point p2) {
	return (sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2)));
}

void graham_scan(point PointSet[], point ch[], int n, int &len) {
	int k = 0;
	int top = 2;
	point tmp;

	//找到最下且偏左的那个点
	for (int i = 1; i < n; i++) {
		if ((PointSet[i].y < PointSet[k].y) || ((PointSet[i].y == PointSet[k].y) && (PointSet[i].x < PointSet[k].x)))
			k = i;
		//将这个点指定为PointSet[0]
		tmp = PointSet[0];
		PointSet[0] = PointSet[k];
		PointSet[k] = tmp;
	}

	//按极角从小到大,距离偏短进行排序
	for (int i = 1; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if ((multiply(PointSet[j], PointSet[k], PointSet[0])>0)
				|| ((multiply(PointSet[j], PointSet[k], PointSet[0]) == 0)
					&& (distant(PointSet[0], PointSet[j]) < distant(PointSet[0], PointSet[k]))))
				k = j;//k保存极角最小的那个点,或者相同距离原点最近
		}
		tmp = PointSet[i];
		PointSet[i] = PointSet[k];
		PointSet[k] = tmp;
	}

	//第三个点先入栈
	ch[0] = PointSet[0];
	ch[1] = PointSet[1];
	ch[2] = PointSet[2];

	//判断与其余所有点的关系
	for (int i = 3; i<n; i++)
	{
		//不满足向左转的关系,栈顶元素出栈
		while (multiply(PointSet[i], ch[top], ch[top - 1]) >= 0)
			top--;
		//当前点与栈内所有点满足向左关系,因此入栈.
		ch[++top] = PointSet[i];
	}
	len = top + 1;
}
double dis(point p1, point p2) {
	return(sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)));
}

int main() {

	int n, d;
	double perimeter;//栅栏周长为pi*D*(凸包顶点个数-2)+凸包的周长
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%lf", &PointSet[i].x);
			scanf("%lf", &PointSet[i].y);
		}
		graham_scan(PointSet, ch, n, len);
		perimeter = 0;
		for (int i = 0; i < len-1; i++) {
			perimeter += dis(ch[i], ch[i + 1]);
		}
		perimeter += dis(ch[len - 1], ch[0]);
		cout << perimeter ;
//		perimeter += 3.141592653*d*2;
//		cout << (int)(perimeter+0.5) << endl;
	}
}
