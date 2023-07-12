#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int,int>> * link = new vector<pair<int,int>> [n];
    long long int prevS = 0;
    for(int i=0;i<m;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        link[a].push_back({b, c});
        link[b].push_back({a, c});
        prevS += c;
    }
    vector<int> check(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        pair<int,int> nw = pq.top();
        pq.pop();
        if(check[nw.second] != 0){
            continue;
        }
        check[nw.second] = 1;
        prevS -= nw.first;
        
        for(int i=0;i<link[nw.second].size();i++){
            pair<int,int> nx = link[nw.second][i];
            if(check[nx.first] == 0){
                pq.push({nx.second, nx.first});
            }
        }
    }
    int checkN = 0;
    for(int i=0;i<n;i++){
        checkN += check[i];
    }
    if(checkN != n){
        printf("-1\n");
    }else{
        printf("%lld\n", prevS);
    }
    return 0;
}