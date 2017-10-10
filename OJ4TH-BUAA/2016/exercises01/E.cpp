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
            //����һ���洢�������ܵĶ���
            priority_queue<frog> two;

            //ȡ����һ��
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
                //���ֻ��һֻ����
                if(two.size()==1){
                    flag=false; //����
                    tmp = two.top();
                    two.pop();
                    tmp.start += tmp.jump;
                    one.push(tmp);

                    //λ�ã�
                }
                else{
                    tmp = two.top();
                    two.pop();
                    int cntb=1;

                    //ȡ��������ͬ��
                    while(two.top().jump==tmp.jump){
                        two.pop();
                        cntb++;
                        if(two.empty())
                            break;
                    }

                    //���ȫ����ͬ
                    if(!two.size())
                        flag=false; //ץ����������
                    //����в�ͬ
                    else
                        cnt+=two.size(); //��¼ץ��������

                    tmp.start += tmp.jump;
                    while(cntb--) one.push(tmp);
                }
            }
            else{ //����ʱ
                walk = tmp.start; //��¼����
                flag = true;
            }
        }

        cout << walk << " " << cnt << endl;
    }



}
