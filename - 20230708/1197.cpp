#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    vector<pair<int,int>> * link = new vector<pair<int,int>> [v];
    int lengN = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int * check = new int[v];

    for(int i=0;i<e;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        link[a-1].push_back({b-1, c});
        link[b-1].push_back({a-1, c});
    }

    pq.push({0, 0});
    while(1){
        if(pq.empty()){
            break;
        }
        pair<int, int> nw = pq.top();
        pq.pop();
        if(check[nw.second] == 1){
            continue;
        }
        check[nw.second] = 1;
        lengN += nw.first;

        for(int i=0;i<link[nw.second].size();i++){
            if(check[link[nw.second][i].first] == 1){
                continue;
            }
            pq.push({link[nw.second][i].second, link[nw.second][i].first});
        }
    }
    printf("%d\n", lengN);
    return 0;
}