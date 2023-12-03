#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    int s, e;
    cin >> s >> e;
    
    vector<pair<int, int>> * v = new vector<pair<int,int>> [n];
    unordered_map<int, set<int>> um;

    int x, y, c;
    while(m--){
        cin >> x>> y >> c;
        v[x].push_back(make_pair(y, c));
    }
    int a, b;
    while(k--){
        cin >> a >> b >> c;
        um[a * 30000 + b].insert(c);
    }

    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
    unordered_map<int, bool> check;
    long long length = -1;
    pq.push(make_pair(0, make_pair(s, -1)));

    while(!pq.empty()){
        pair<long long, pair<int, int>> nw = pq.top();
        pq.pop();
        if(nw.second.first == e){
            length = nw.first;
            break;
        }
        check[nw.second.second * 30000 + nw.second.first] = true;
        for(int i=0; i < v[nw.second.first].size(); i++){
            int next = v[nw.second.first][i].first;
            int cost = v[nw.second.first][i].second;
            int hash = nw.second.second * 30000 + nw.second.first;
            if(um[hash].find(next) == um[hash].end() && check[nw.second.first * 30000 + next] == false){
                pq.push(make_pair(nw.first+cost, make_pair(next, nw.second.first)));
            }
        }
    }
    cout << length << endl;
    return 0;
}