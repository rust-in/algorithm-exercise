#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int last;
    long long time;

    bool operator < (const node &tmp) const {
        if(time==tmp.time)
            return last<tmp.last;
        return time>tmp.time;
    }
};

int main()
{
    int len;
    while(~scanf("%d",&len)){
        int oper[35] = {0};
        int tmp,gap;
        for(int i=0;i<len;i++){
            scanf("%d", &tmp);
            oper[tmp]++;
        }   scanf("%d",&gap);
        priority_queue<node> que;
        long long time = 0;
        for(int i=1;i<=30;i++)
            if(oper[i]>0){
                node one;
                one.last = oper[i];
                one.time = 0;
                que.push(one);
            }
        while(!que.empty()){
            node now = que.top();
            que.pop();
            while(now.time<time){//�����������ʱ����и���
                now.time = time;
                que.push(now);
                now = que.top();
                que.pop();
            }

            if(time<now.time)   time = now.time;
            time++; //���ӵ��ǵ�ǰִ�е���һ�������ʱ��
            now.last-=1;
            now.time = time + gap;
            if(now.last)
                que.push(now);
        }
        printf("%lld\n",time);
    }
}
