#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x, y;
    cin >> x >> y;
    int z = (long long int)y * 100 / x;
    if(z >= 99){
        cout << -1;
    }else{
        long long int z1 = (long long int)x * z + x - 100 * (long long int)y;
        int z2 = 99 - z;
        if(z1 % z2 == 0){
            cout << z1 / z2;
        }else{
            cout << z1 / z2 + 1;
        }
    }
    return 0;
}
