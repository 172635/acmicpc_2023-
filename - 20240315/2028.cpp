#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int len = 10;
        if(n >= 1000){
            len = 10000;
        }else if(n >= 100){
            len = 1000;
        }else if(n >= 10){
            len = 100;
        }
        int x = n * n;
        if(x % len == n){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}