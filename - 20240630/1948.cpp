#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> * link = new vector<pair<int,int>> [n];
    vector<int> * link_rev = new vector<int> [n];
    vector<pair<int,int>> * time_number = new vector<pair<int,int>> [n];
    vector<int> linkin(n,0);
    for(int i=0;i<m;i++){
        int s, e, d;
        cin >> s >> e >> d;
        link[s-1].push_back({e-1, d});
        link_rev[e-1].push_back(s-1);
        linkin[e-1] ++;
    }
    queue<int> q;
    int s, e;
    cin >> s >> e;
    s--;
    e--;
    q.push(s);
    set<int> rest;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int time = 0;
        queue<int> norest;
        for(int i=0;i<time_number[now].size();i++){
            pair<int,int> tnn = time_number[now][i];
            if(time < tnn.first){
                time = tnn.first;
                while(!norest.empty()){
                    int from = norest.front();
                    norest.pop();
                    rest.insert(now*n+from);
                }
                norest.push(tnn.second);
            }else if(time == tnn.first){
                norest.push(tnn.second);
            }else{
                rest.insert(now*n+tnn.second);
            }
        }
        for(int i=0;i<link[now].size();i++){
            int next = link[now][i].first;
            int ntime = link[now][i].second + time;
            linkin[next] --;
            if(linkin[next] == 0){
                q.push(next);
            }
            time_number[next].push_back({ntime, now});
        }
        if(now == e){
            cout << time << "\n";
        }
    }
    int norest = 0;
    queue<int> qr;
    qr.push(e);
    vector<int> check(n,0);
    while(!qr.empty()){
        int now = qr.front();
        qr.pop();
        for(int i=0;i<link_rev[now].size();i++){
            int prev = link_rev[now][i];
            if(rest.find(now*n+prev) == rest.end()){
                norest ++;
                if(check[prev] == 0){
                    check[prev] = 1;
                    qr.push(prev);
                }
            }
        }
    }
    cout << norest << "\n";
    return 0;
}