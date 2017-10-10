#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

struct frog
{
    int start;
    int jump;

    bool operator < (const frog &a) const
    {
        if(a.start!=start)
            return a.start<start;
        else
            return a.jump>jump;
    }
};

frog num[100005];

int main()
{
    priority_queue<frog> one;
    int t,len;
    cin >> t;
    while(t--)
    {
        cin >> len; frog tmp;   int walk=0,cnt=0;
        for(int i=0;i<len;i++)
        {
            cin >> tmp.start >> tmp.jump;
            one.push(tmp);
        }

        bool flag = true;

        while(!one.empty())
        {
            //创建一个存储出队青蛙的队列
            priority_queue<frog> two;

            //取出第一个
            tmp = one.top();
            one.pop();
            two.push(tmp);

            if(one.size()){
                while(one.top().start==tmp.start){
                    two.push(one.top());
                    one.pop();
                    if(one.empty())
                        break;
                }
            }

            if(flag)
            {
                //如果只有一只青蛙
                if(two.size()==1){
                    flag=false; //气馁
                    tmp = two.top();
                    two.pop();
                    tmp.start += tmp.jump;
                    one.push(tmp);

                    //位置？
                }
                else{
                    tmp = two.top();
                    two.pop();
                    int cntb=1;

                    //取出所有相同的
                    while(two.top().jump==tmp.jump){
                        two.pop();
                        cntb++;
                        if(two.empty())
                            break;
                    }

                    //如果全部相同
                    if(!two.size())
                        flag=false; //抓不到，气馁
                    //如果有不同
                    else
                        cnt+=two.size(); //记录抓到的青蛙

                    tmp.start += tmp.jump;
                    while(cntb--) one.push(tmp);
                }
            }
            else{ //气馁时
                walk = tmp.start; //记录距离
                flag = true;
            }
        }

        cout << walk << " " << cnt << endl;
    }



}
