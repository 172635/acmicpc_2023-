#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a > b){
            int temp = b;
            b = a;
            a = temp;
        }
        if(a == b){
            cout << a << ' ' << 3 << '\n';
        }else if(b <= 2 * a){
            cout << a << ' ' << 7 << '\n';
        }else if(b <= 2 * a + 2){
            cout << a+1 << ' ' << ((a==1 && b==3)?5:7) << '\n';
        }else{
            cout << a+1 << ' ' << 2*b-4*a+3 << '\n';
        }
    }
    return 0;
}