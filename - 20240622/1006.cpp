#include <bits/stdc++.h>

using namespace std;

int min(int * arg){
    int s = sizeof(arg)/sizeof(int);
    int _min = 10000;
    for(int i=0;i<s;i++){
        if(_min > arg[s]){
            _min = arg[s];
        }
    }
    return _min;
}

int Cal(int a1, int a2, int b1, int b2, int w){
    int x = 4;
    if(a1 + a2 <= w){
        x = 3;
        if(b1 + b2 <= w){
            return 2;
        }
    }
    if(b1 + b2 <= w){
        x = 3;
    }
    if(a1 + b1 <= w){
        x = 3;
        if(a2 + b2 <= w){
            return 2;
        }
    }
    if(a2 + b2 <= w){
        x = 3;
    }
    return x;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    int n, w, x;
    int now[4];
    int next[4];
    while(t--){
        cin >> n >> w;
        vector<int> n1, n2;
        for(int i=0;i<n;i++){
            cin >> x;
            n1.push_back(x);
        }
        for(int i=0;i<n;i++){
            cin >> x;
            n2.push_back(x);
        }
        int _min = 2 * n;
        for(int st=0;st<4;st++){//0 : empty / 1 : empty2 / 2 : empty1 / 3 : full
            for(int i=0;i<4;i++){
                now[i] = 2 * n;
                now[st] = 0;
            }
            for(int idx = 1;idx < n;idx++){
                next[0] = min({now[0] + (n1[idx-1] + n2[idx-1] > w ? 2 : 1), now[1] + 1, now[2] + 1, now[3]});
                next[1] = min({now[0] + (n1[idx-1] + min({n1[idx], n2[idx-1]}) > w ? 3 : 2), now[1] + 2, now[2] + (n1[idx-1] + n1[idx] > w ? 2 : 1), now[3] + 1});
                next[2] = min({now[0] + (n2[idx-1] + min({n1[idx-1], n2[idx]}) > w ? 3 : 2), now[1] + (n2[idx-1] + n2[idx] > w ? 2 : 1), now[2] + 2, now[3] + 1});
                next[3] = min({now[0] + Cal(n1[idx-1], n1[idx], n2[idx-1], n2[idx], w), now[1] + (n2[idx] + min({n2[idx-1], n1[idx]}) > w ? 3 : 2), now[2] + (n1[idx] + min({n1[idx-1], n2[idx]}) > w ? 3 : 2), now[3] + (n1[idx] + n2[idx] > w ? 2 : 1)});

                for(int i=0;i<4;i++){now[i] = next[i];}
            }
            if(st == 0){
                _min = min({_min, now[0] + (n1[n-1] + n2[n-1] > w ? 2 : 1), now[1] + 1, now[2] + 1, now[3]});
            }else if(st == 1){
                _min = min({_min, now[0] + (n1[n-1] + min({n1[0], n2[n-1]}) > w ? 3 : 2), now[1] + 2, now[2] + (n1[n-1] + n1[0] > w ? 2 : 1), now[3] + 1});
            }else if(st == 2){
                _min = min({_min, now[0] + (n2[n-1] + min({n1[n-1], n2[0]}) > w ? 3 : 2), now[1] + (n2[n-1] + n2[0] > w ? 2 : 1), now[2] + 2, now[3] + 1});
            }else if(st == 3){
                _min = min({_min, now[0] + Cal(n1[n-1], n1[0], n2[n-1], n2[0], w), now[1] + (n2[0] + min({n2[n-1], n1[0]}) > w ? 3 : 2), now[2] + (n1[0] + min({n1[n-1], n2[0]}) > w ? 3 : 2), now[3] + (n1[0] + n2[0] > w ? 2 : 1)});
            }
        }
        cout << _min << "\n";
    }
    return 0;
}