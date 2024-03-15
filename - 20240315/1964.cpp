#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    cout << (1 + n + 3 * n * (n+1) / 2)%45678;
    return 0;
}