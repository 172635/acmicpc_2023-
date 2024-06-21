#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, M, t, r;
    cin >> n >> m >> M >> t >> r;
    if(M-m < t){
        cout << -1 << endl;
    }else{
        int time = 0;
        int now = m;
        while(n > 0){
            while(now + t > M){
                time ++;
                now -= r;
                if(now < m){
                    now = m;
                }
            }
            time ++;
            n --;
            now += t;
        }
        cout << time << endl;
    }
    return 0;
}