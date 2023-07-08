#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    int init;
    scanf("%d", &init);
    init --;
    vector<pair<int,int>> * link = new vector<pair<int,int>>[v];
    for(int i=0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        link[u -1].push_back({v -1, w});
    }
    int * path = new int [v];
    for(int i=0;i<v;i++){
        path[i] = -1;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, init});
    while(!pq.empty()){
        pair<int,int> nw = pq.top();
        pq.pop();
        if(path[nw.second] != -1){
            continue;
        }
        path[nw.second] = nw.first;
        for(int i=0;i<link[nw.second].size();i++){
            int nx = link[nw.second][i].first;
            int nxw = link[nw.second][i].second;
            if(path[nx] != -1){
                continue;
            }
            pq.push({path[nw.second] + nxw, nx});
        }
    }
    for(int i=0;i<v;i++){
        if(path[i] == -1){
            printf("INF\n");
        }else{
            printf("%d\n", path[i]);
        }
    }
    return 0;
}