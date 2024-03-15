#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    if(b >= c){
        cout << -1;
    }else{
        c -= b;
        cout << a / c + 1;
    }
    return 0;
}