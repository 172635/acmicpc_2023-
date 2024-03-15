#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    int x = 0;
    while(n--){
        string st;
        cin >> st;
        int c = 0;
        for(int i=0;i<m;i++){
            if(st[i] == 'X'){
                v[i] = 1;
                c = 1;
            }
        }
        if(c == 0){
            x ++;
        }
    }
    int y = 0;
    for(int i=0;i<m;i++){
        if(v[i] == 0){
            y ++;
        }
    }
    cout << (x > y ? x : y) << '\n';
    return 0;
}