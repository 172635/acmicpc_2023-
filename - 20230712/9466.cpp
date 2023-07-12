#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int c1=0;c1<t;c1++){
        int n;
        scanf("%d", &n);
        vector<int> link;
        vector<int> check;
        for(int c2=0;c2<n;c2++){
            int x;
            scanf("%d", &x);
            x--;
            link.push_back(x);
            check.push_back(0);
        }
        queue<int> q;
        int nonSet = n;
        for(int i=0;i<n;i++){
            if(check[i] == 0){
                q.push(i);
            }
            vector<int> nwcheck;
            int onSet = 0;
            while(!q.empty()){
                int nw = q.front();
                q.pop();
                nwcheck.push_back(nw);
                if(check[nw] == 1){
                    continue;
                }
                check[nw] = 1;
                if(link[nw] == i){
                    onSet = 1;
                    nonSet -= nwcheck.size();
                    break;
                }
                q.push(link[nw]);
            }
            if(onSet == 0){
                int size = nwcheck.size();
                for(int j=size-2;j>=0;j--){
                    if(nwcheck[j] == nwcheck[size-1]){
                        nonSet -= (size - j - 1);
                        break;
                    }
                }
            }
        }
        printf("%d\n", nonSet);
    }
    return 0;
}