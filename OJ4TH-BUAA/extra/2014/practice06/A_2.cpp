#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

struct Point
{
    double x, y;
};

struct line{
    Point start;
    Point last;
}num[100000];

bool flag[100000];

/* 求出向量 AB 与向量 AC 的向量积,返回 0 代表共线 */
double cross(Point A, Point B, Point C)
{
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

/* 判断线段 AB 与线段 CD 是否相交，相交返回 true */
bool is_intersect(Point A, Point B, Point C, Point D)
{
    if (min(A.x, B.x) <= max(C.x, D.x) &&
        min(C.x, D.x) <= max(A.x, B.x) &&
        min(A.y, B.y) <= max(C.y, D.y) &&
        min(C.y, D.y) <= max(A.y, B.y) &&
        cross(A, B, C) * cross(A, B, D) <= 0 &&
        cross(C, D, A) * cross(C, D, B) <= 0)
        return true;

    return false;
}

int main()
{
    int len;
    while(cin>>len){
        for(int i=1;i<=len;i++){
            cin >> num[i].start.x >> num[i].start.y >> num[i].last.x >> num[i].last.y;
            flag[i] = true;
        }
        for(int i=1;i<=len;i++){
            for(int j=i+1;j<=len;j++){
                if(is_intersect(num[i].start,num[i].last,num[j].start,num[j].last))
                    flag[i]=false;
            }
        }

        for(int i=1;i<=len;i++)
            if(flag[i])
                cout << i << " ";
        cout << endl;
    }
}
