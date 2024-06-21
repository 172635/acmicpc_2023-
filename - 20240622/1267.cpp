#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int y = 0;
    int m = 0;
    while(n--){
        int x;
        cin >> x;
        y += x / 30 * 10 + 10;
        m += x / 60 * 15 + 15;
    }
    if(y < m){
        cout << "Y " << y;
    }else if(y > m){
        cout << "M " << m;
    }else{
        cout << "Y M " << y;
    }
    return 0;
}