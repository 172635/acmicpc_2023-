#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int minT = 200002;
    int minC = 1;
    int * check = new int [200002];
    for(int i=0;i<200002;i++){
        check[i] = 200002;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, n});
    check[n] = 0;
    while(!pq.empty()){
        pair<int,int> nw = pq.top();
        pq.pop();
        if(nw.second == k){
            if(minT > nw.first){
                minT = nw.first;
                minC = 1;
            }else if(minT == nw.first){
                minC ++;
            }
            continue;
        }else if(nw.second > k){
            int x = nw.second - k;
            if(minT > nw.first + x){
                minT = nw.first + x;
                minC = 1;
            }else if(minT == nw.first + x){
                minC ++;
            }
            continue;
        }else if(nw.second == 0){
            if(check[1] >= nw.first + 1){
                check[1] = nw.first + 1;
                pq.push({nw.first + 1, 1});
            }
            continue;
        }

        int nxt = nw.first + 1;
        if(check[nw.second - 1] >= nxt){
            check[nw.second - 1] = nxt;
            pq.push({nxt, nw.second - 1});
        }
        if(check[nw.second + 1] >= nxt){
            check[nw.second + 1] = nxt;
            pq.push({nxt, nw.second + 1});
        }
        if(check[nw.second * 2] >= nxt){
            check[nw.second * 2] = nxt;
            pq.push({nxt, nw.second * 2});
        }
    }
    printf("%d\n%d\n", minT, minC);
    return 0;
}