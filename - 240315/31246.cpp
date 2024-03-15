#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> ai;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        int z = y - x;
        if(z < 0){
            z = 0;
        }
        ai.push_back(z);
    }
    sort(ai.begin(), ai.end());
    cout << ai[k-1];
    return 0;
}