#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;
    x--;
    vector<pair<int,int>> * linkout = new vector<pair<int,int>> [n];
    vector<pair<int,int>> * linkin = new vector<pair<int,int>> [n];
    for(int i=0;i<m;i++){
        int is, ie, ti;
        cin >> is >> ie >> ti;
        is--;
        ie--;
        linkout[is].push_back({ie, ti});
        linkin[ie].push_back({is, ti});
    }
    vector<int> distout(n, 1000000);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pqout;
    pqout.push({0, x});
    while(!pqout.empty()){
        pair<int,int> now = pqout.top();
        pqout.pop();
        int nowpos = now.second;
        int nowtime = now.first;
        if(distout[nowpos] <= nowtime){continue;}
        distout[nowpos] = nowtime;
        for(int i=0;i<linkout[now.second].size();i++){
            int nextpos = linkout[now.second][i].first;
            int nexttime = linkout[now.second][i].second + nowtime;
            if(distout[nextpos] > nexttime){
                pqout.push({nexttime, nextpos});
            }
        }
    }

    vector<int> distin(n, 1000000);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pqin;
    pqin.push({0, x});
    while(!pqin.empty()){
        pair<int,int> now = pqin.top();
        pqin.pop();
        int nowpos = now.second;
        int nowtime = now.first;
        if(distin[nowpos] <= nowtime){continue;}
        distin[nowpos] = nowtime;
        for(int i=0;i<linkin[now.second].size();i++){
            int nextpos = linkin[now.second][i].first;
            int nexttime = linkin[now.second][i].second + nowtime;
            if(distin[nextpos] > nexttime){
                pqin.push({nexttime, nextpos});
            }
        }
    }
    
    int max_idx = 0;
    for(int i=1;i<n;i++){
        if(distout[i] + distin[i] > distout[max_idx] + distin[max_idx]){
            max_idx = i;
        }
    }
    cout << distout[max_idx] + distin[max_idx] << "\n";
    return 0;
}