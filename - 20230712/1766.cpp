#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> precount(n, 0);
    vector<int> * link = new vector<int> [n];
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        link[a].push_back(b);
        precount[b] ++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        if(precount[i] == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int nw = pq.top();
        pq.pop();
        printf("%d ", nw+1);
        for(int i=0;i<link[nw].size();i++){
            int nx = link[nw][i];
            precount[nx] --;
            if(precount[nx] == 0){
                pq.push(nx);
            }
        }
    }
    printf("\n");
    return 0;
}