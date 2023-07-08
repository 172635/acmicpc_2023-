#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    vector<int> * link = new vector<int> [n];
    int * dis = new int [n];
    for(int i=0;i<n;i++){
        dis[i] = -1;
    }
    int a, b;
    scanf("%d %d", &a, &b);
    a --;
    b --;
    int k;
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        int p, q;
        scanf("%d %d", &p, &q);
        link[p -1].push_back(q -1);
        link[q -1].push_back(p -1);
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, a});
    while(!pq.empty()){
        pair<int,int> nw = pq.top();
        pq.pop();
        if(dis[nw.second] != -1){
            continue;
        }
        dis[nw.second] = nw.first;
        if(nw.second == b){
            break;
        }
        for(int i=0;i<link[nw.second].size(); i++){
            if(dis[link[nw.second][i]] != -1){
                continue;
            }
            pq.push({nw.first+1, link[nw.second][i]});
        }
    }
    printf("%d\n", dis[b]);
    return 0;
}