#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

struct point {
	double x, y;
};

/*
PointSet[]������ĵ㼯
ch[]�������͹���ϵĵ㼯��������ʱ�뷽������
n��PointSet�еĵ����Ŀ
len�������͹���ϵĵ�ĸ���
*/
const int maxN = 1000;
point PointSet[maxN];
point ch[maxN];
int n;
int len;

//С��0,˵������p0p1�ļ��Ǵ���p0p2�ļ���
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

	//�ҵ�������ƫ����Ǹ���
	for (int i = 1; i < n; i++) {
		if ((PointSet[i].y < PointSet[k].y) || ((PointSet[i].y == PointSet[k].y) && (PointSet[i].x < PointSet[k].x)))
			k = i;
		//�������ָ��ΪPointSet[0]
		tmp = PointSet[0];
		PointSet[0] = PointSet[k];
		PointSet[k] = tmp;
	}

	//�����Ǵ�С����,����ƫ�̽�������
	for (int i = 1; i < n - 1; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if ((multiply(PointSet[j], PointSet[k], PointSet[0])>0)
				|| ((multiply(PointSet[j], PointSet[k], PointSet[0]) == 0)
					&& (distant(PointSet[0], PointSet[j]) < distant(PointSet[0], PointSet[k]))))
				k = j;//k���漫����С���Ǹ���,������ͬ����ԭ�����
		}
		tmp = PointSet[i];
		PointSet[i] = PointSet[k];
		PointSet[k] = tmp;
	}

	//������������ջ
	ch[0] = PointSet[0];
	ch[1] = PointSet[1];
	ch[2] = PointSet[2];

	//�ж����������е�Ĺ�ϵ
	for (int i = 3; i<n; i++)
	{
		//����������ת�Ĺ�ϵ,ջ��Ԫ�س�ջ
		while (multiply(PointSet[i], ch[top], ch[top - 1]) >= 0)
			top--;
		//��ǰ����ջ�����е����������ϵ,�����ջ.
		ch[++top] = PointSet[i];
	}
	len = top + 1;
}
double dis(point p1, point p2) {
	return(sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)));
}

int main() {

	int n, d;
	double perimeter;//դ���ܳ�Ϊpi*D*(͹���������-2)+͹�����ܳ�
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
