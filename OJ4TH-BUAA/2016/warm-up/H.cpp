#include <queue>
#include <iostream>
using namespace std;

/**
���ȶ��е�ʹ��
*/

struct cmp{
    bool operator()(int &a, int &b){
        return a>b; //С�����ȼ���
    }
};

int main()
{
    priority_queue<int,vector<int>,cmp> que;
//    priority_queue<int,vector<int>,greater<int>> que;
    int len;
    while(cin>>len){
        for(int i=0;i<len;i++){
            int tmp;
            cin>>tmp;
            que.push(tmp);
        }
        long res=0;
        while(!que.empty()){
            int a=que.top();
            que.pop();
            if(que.empty())
                break;
            int b=que.top();
            que.pop();
            res+=(a+b);
            que.push(a+b);
        }
        cout << res << endl;
    }
}
