#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<string,int>> v;
    while(n--){
        string x;
        cin >> x;
        int sum = 0;
        for(int i=0;i<x.length();i++){
            if(x[i] >= '0' && x[i] <= '9'){
                sum += x[i] - '0';
            }
        }
        v.push_back({x, sum});
    }
    for(int j=0;j<v.size();j++){
        for(int i=v.size()-1;i>j;i--){
            if(v[i].first.length() < v[i-1].first.length() || (v[i].first.length() == v[i-1].first.length() && (v[i].second < v[i-1].second || (v[i].second == v[i-1].second && v[i].first < v[i-1].first)))){
                pair<string,int> temp = v[i-1];
                v[i-1] = v[i];
                v[i] = temp;
            }
        }
        cout << v[j].first << '\n';
    }
    return 0;
}