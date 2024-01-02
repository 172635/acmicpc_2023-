#include <bits/stdc++.h>

using namespace std;

int p = 1000000007;

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    vector<int> a(5001);
    vector<int> c[5001];
    a[0] = 1;
    a[1] = 1;
    c[0].push_back(1);
    c[1].push_back(1);
    c[1].push_back(1);
    for(int i=2;i<=5000;i++){
        a[i] = 0;
        for(int j=0;j<i-1;j++){
            a[i] = (a[i] + (((long long int)(c[i-1][j]) * a[j]) %p) * a[i-j-1] * 2 ) %p;
            c[i].push_back(c[i-1][j]);
        }
        a[i] = (a[i] + (((long long int)(c[i-1][i-1]) * a[i-1]) %p) * a[0]) %p;
        c[i].push_back(c[i-1][i-1]);
        c[i].push_back(1);
        for(int j=i-1;j>=1;j--){
            c[i][j] = ((long long int)(c[i][j]) + c[i][j-1]) %p;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n==k){
            cout << a[k-1] << '\n';
        }else{
            cout << ((((long long int)(c[n-1][k-1]) * a[k-1]) %p) * a[n-k] * 2) %p << '\n';
        }
    }
    return 0;
}