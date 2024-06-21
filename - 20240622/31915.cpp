#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>>* link = new vector<pair<int,int>> [n+1];
    while(m--){
        int s, e, d;
        cin >> s >> e >> d;
        link[s].push_back(make_pair(e, d));
        link[e].push_back(make_pair(s, d));
    }
    vector<long long int>* dist = new vector<long long int> [n+1];
    unordered_map<int, bool> um[n+1];
    int left = n;
    priority_queue<pair<long long int, pair<int,int>>, vector<pair<long long int, pair<int, int>>>, greater<pair<long long int, pair<int, int>>>> pq;
    //dist / now / start
    for(int s=1; s<=k;s++){
        pq.push(make_pair(0, make_pair(s, s)));
    }
    while(!pq.empty()){
        pair<long long int, pair<int, int>> now = pq.top();
        pq.pop();
        long long int nowlen = now.first;
        int nowpos = now.second.first;
        int nowstt = now.second.second;
        if(um[nowpos].find(nowstt) == um[nowpos].end()){
            um[nowpos][nowstt] = true;
            if(dist[nowpos].size() < 2){
                dist[nowpos].push_back(nowlen);
            }else{
                if(dist[nowpos].size() == 2){
                    dist[nowpos].push_back(0);
                    left --;
                    if(left == 0){break;}
                }
                continue;
            }
            for(int i=0;i<link[nowpos].size();i++){
                int newpos = link[nowpos][i].first;
                long long int newlen = nowlen + link[nowpos][i].second;
                if(um[newpos].find(nowstt) == um[newpos].end()){
                    pq.push(make_pair(newlen, make_pair(newpos, nowstt)));
                }
            }
        }
    }
    for(int e=k+1;e<n+1;e++){
        cout << dist[e][1] << " ";
    }
    return 0;
}