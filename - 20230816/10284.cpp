#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int ti=0;ti<t;ti++){
        int n;
        scanf("%d", &n);
        int * pp = new int [n+1];
        for(int i=0;i<=n;i++){
            pp[i] = 0;
        }
        int rest = 0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d", &x);
            pp[i] = x;
            rest += x;
        }
        int * angr = new int [n+1];
        angr[0] = 0;
        for(int i=1;i<=n;i++){
            angr[i] = 2000000000;
        }
        for(int i=1;i<=n;i++){
            rest -= pp[i];
            int sk = 0;
            for(int j=i-1;j>=0;j--){
                int nw = angr[j] + rest + sk;
                if(nw < angr[i]){
                    angr[i] = nw;
                }
                sk += (i - j) * pp[j];
            }
        }
        printf("%d\n", angr[n]);
    }
    return 0;
}

