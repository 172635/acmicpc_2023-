#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int _max = 33554432;
    int _maxlen = 33554432/31+1;

    vector<int> bitmask(_maxlen, 0);
    while(true){
        int x;
        cin >> x;
        if(cin.eof()) break;
        int xn = x/31;
        int xi = x%31;
        if((bitmask[xn] & (1 << xi)) == 0){
            bitmask[xn] += (1 << xi);
            cout << x << " ";
        }
    }
}