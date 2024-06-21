#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int map[30][30];
    int check_map[30][30];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            map[j][i] = x;
            check_map[j][i] = 0;
        }
    }
    vector<int> v;
    priority_queue<pair<int,pair<int,pair<int,int>>>> pq;
    pq.push(make_pair(0, make_pair(map[0][0], make_pair(0,0)))); // -ij // map
    int ij = 1;
    while(!pq.empty()){
        pair<int,pair<int,pair<int,int>>> now = pq.top();
        pq.pop();
        if(ij > now.first){
            ij = now.first;
            v.push_back(now.second.first);
        }else{
            if(v[-ij] != now.second.first){
                continue;
            }
        }
        int x = now.second.second.first;
        int y = now.second.second.second;
        if(x < n-1 && check_map[x+1][y] == 0){
            pq.push(make_pair(ij - 1, make_pair(map[x+1][y], make_pair(x+1, y))));
            check_map[x+1][y] = 1;
        }
        if(y < n-1 && check_map[x][y+1] == 0){
            pq.push(make_pair(ij - 1, make_pair(map[x][y+1], make_pair(x, y+1))));
            check_map[x][y+1] = 1;
        }
    }
    long long int val = 0;
    for(int i=0;i<n*2-1;i++){
        val *= 2;
        val += v[i];
    }
    cout << val;
    return 0;
}