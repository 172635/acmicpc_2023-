#include <bits/stdc++.h>

using namespace std;

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> alpha[26];
    vector<char> stick;
    vector<int> dec;
    vector<int> apc;
    for(int i=0;i<m;i++){
        char x;
        int y, z;
        cin >> x;
        cin >> y >> z;
        alpha[x-'a'].push_back(i);
        stick.push_back(x);
        dec.push_back(y);
        apc.push_back(z);
    }
    vector<int> now;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        now.push_back(x-1);
    }
    string goal;
    cin >> goal;

    int minsum = -1;
    int nowsum = 0;
    for(int i=0;i<=n-k;i++){
        nowsum = 0;
        vector<int> needalpha(26);
        vector<int> zeroalpha(26);
        for(int j=0;j<k;j++){
            if(stick[now[i+j]] != goal[j]){
                needalpha[goal[j] - 'a'] ++;
                zeroalpha[stick[now[i+j]] - 'a'] ++;
                nowsum += dec[now[i+j]];
            }
        }
        vector<int> apalpha(26);
        for(int j=0;j<26;j++){
            apalpha[j] = 10000;
        }
        priority_queue<int, vector<int>, greater<int>> pqalpha[26];
        for(int j=0;j<i;j++){
            pqalpha[stick[now[j]] - 'a'].push(dec[now[j]]);
        }
        for(int j=i+k;j<n;j++){
            pqalpha[stick[now[j]] - 'a'].push(dec[now[j]]);
        }
        for(int j=0;j<m;j++){
            apalpha[stick[j] - 'a'] = min(apalpha[stick[j] - 'a'], apc[j]);
        }
        for(int j=0;j<26;j++){
            if(needalpha[j] > zeroalpha[j]){
                int nd = needalpha[j] - zeroalpha[j];
                while(nd--){
                    if(!pqalpha[j].empty()){
                        if(pqalpha[j].top() < apalpha[j]){
                            nowsum += pqalpha[j].top();
                            pqalpha[j].pop();
                        }else{
                            nowsum += apalpha[j];
                        }
                    }else if(apalpha[j] <= 1000){
                        nowsum += apalpha[j];
                    }else{
                        nowsum = -1;
                        j = 26;
                        break;
                    }
                }
            }
        }
        if(minsum == -1 || (nowsum != -1 && nowsum < minsum)){
            minsum = nowsum;
        }
    }
    cout << minsum << '\n';
    cout << flush;
    return 0;
}