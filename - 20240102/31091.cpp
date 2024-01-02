#include <bits/stdc++.h>

using namespace std;

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v1(n+1);
    vector<int> v2(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x > 0){
            v1[x] ++;
        }else{
            v2[-x] ++;
        }
    }
    for(int i=1;i<=n;i++){
        v1[i] += v1[i-1];
        v2[n-i] += v2[n-i+1];
    }
    vector<int> v3;
    for(int i=0;i<=n;i++){
        if(n-i == v1[i] + v2[i]){
            v3.push_back(i);
        }
    }
    cout << v3.size() << '\n';
    for(int i=0;i<v3.size();i++){
        cout << v3[i] << ' ';
    }
    return 0;
}