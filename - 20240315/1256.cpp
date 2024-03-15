#include <bits/stdc++.h>

using namespace std;

int maxi = 1000000000;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    int s = n + m;
    vector<int> v[s+1];
    v[0].push_back(1);
    for(int i=1;i<=s;i++){
        v[i].push_back(1);
        for(int j=1;j<i;j++){
            v[i].push_back(v[i-1][j]+v[i-1][j-1]);
            if(v[i][j] > maxi){
                v[i][j] = maxi+1;
            }
        }
        v[i].push_back(1);
    }
    if(v[s][n] < k){
        cout << -1;
    }else{
        while(s > 0){
            if(n == 0){
                m --;
                cout << 'z';
            }else if(v[s-1][n-1] < k){
                m --;
                cout << 'z';
                k -= v[s-1][n-1];
            }else{
                n --;
                cout << 'a';
            }
            s--;
        }
    }
    return 0;
}