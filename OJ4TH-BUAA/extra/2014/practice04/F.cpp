#include<iostream>
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        int A[N],k;
        for(int i=0; i<N; i++)
        {
            cin>>A[i];
        }
        cin>>k;
        int j=N-1;
        for(int i=1; i<=k; i++)
        {
            while(j>=0 && A[j]==1)
            {
                A[j]=0;
                j--;
            }
            if(j>=0)
            {
                A[j]=1;
                cout<<"2 ";
            }
            else
            {
                for(int k=0; k<N; k++)
                    A[k]=0;
                cout<<"0 ";
            }
            j=N-1;
        }
        cout<<endl;
    }
}
