#include <bits/stdc++.h>

using namespace std;

int main(){
    int x = 1;
    int m;
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        if(x == a){
            x = b;
        }else if(x == b){
            x = a;
        }
    }
    cout << x << endl;
    return 0;
}