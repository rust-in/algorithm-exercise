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
            return a.jump<jump;
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
        cin >> len;
        for(int i=0;i<len;i++)
        {
            cin >> num[i].start >> num[i].jump;
            one.push(num[i]);
        }

        while(!one.empty())
        {
            frog tmp = one.top();
            cout << tmp.start << " " << tmp.jump << endl;
            one.pop();
        }


    }



}
