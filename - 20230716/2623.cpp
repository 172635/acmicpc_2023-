#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> * link = new vector<int> [n];
    vector<int> linknum(n, 0);
    for(int i=0;i<m;i++){
        int mn;
        scanf("%d", &mn);
        int prev = 0;
        int nw = 0;
        for(int j=0;j<mn;j++){
            prev = nw;
            scanf("%d", &nw);
            nw --;
            if(j==0){
                continue;
            }
            link[prev].push_back(nw);
            linknum[nw] ++;
        }
    }
    vector<int> finalq;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(linknum[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int nw = q.front();
        q.pop();
        finalq.push_back(nw);
        for(int i=0;i<link[nw].size();i++){
            int nx = link[nw][i];
            linknum[nx] --;
            if(linknum[nx] == 0){
                q.push(nx);
            }
        }
    }
    if(finalq.size() == n){
        for(int i=0;i<n;i++){
            printf("%d\n", finalq[i] +1);
        }
    }else{
        printf("0\n");
    }
}