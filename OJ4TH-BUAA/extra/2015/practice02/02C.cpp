//#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct stu
{
    int num;
    int sex;
    int grade;

    bool operator < (const stu &a) const
    {
        if(a.grade==grade){
            if(a.sex==sex){
                return a.num<num;
            }
            return a.sex<sex;
        }
        return a.grade>grade;
    }
};

stu cpt[100005];

int main()
{
//    ios_base::sync_with_stdio(false);
    int len,cnt;
    while(~scanf("%d %d",&len,&cnt)){
        priority_queue<stu> que;
        stu tmp;
        for(int i=0;i<len;i++)
            scanf("%d%d%d",&cpt[i].num,&cpt[i].sex,&cpt[i].grade);

        char ope[7]; int a;
        for(int i=0;i<cnt;i++){
            scanf("%s",ope);
            if(strcmp(ope,"Add")==0){
                scanf("%d",&a);
                que.push(cpt[a-1]);
            }
            else if(strcmp(ope,"Delete")==0)
                que.pop();
            else if(strcmp(ope,"Query")==0){
                tmp = que.top();
                printf("%d %d %d\n",tmp.num,tmp.sex,tmp.grade);
            }
        }
    }
}
