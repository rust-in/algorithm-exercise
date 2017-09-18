#include <cstdio>
using namespace std;

int main()
{
    int num;
    while(~scanf("%d", &num)){
        int tmp,one,two;
        for(int i=0; i<num; i++){
            scanf("%d", &tmp);
            if(i==0)
                one = tmp;
            else{
                if(tmp<one)
                    one = tmp;
            }
        }

        for(int i=0;i<num;i++){
            scanf("%d", &tmp);
            if(i==0)
                two =tmp;
            else{
                if(tmp<two)
                    two = tmp;
            }
        }

        printf("%d\n", one+two );
    }
}
