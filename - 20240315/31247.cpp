#include <bits/stdc++.h>

using namespace std;

long long int Ma = 1000000000000000000;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        long long int n, k;
        cin >> n >> k;
        long long int n2 = 1;
        while(k--){
            n2 *= 2;
            if(n2 > Ma){
                n2 = Ma + 1;
                break;
            }
        }
        long long int re = n / n2 - n / (n2 * 2);
        cout << re << '\n';
    }
    return 0;
}