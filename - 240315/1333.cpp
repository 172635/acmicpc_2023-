#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l, d;
    cin >> n >> l >> d;
    int time = 0;
    int bell = d;
    for(int i=0;i<n;i++){
        time += l;
        while(bell < time){
            bell += d;
        }
        if(bell < time + 5){
            time = bell;
            break;
        }
        time += 5;
    }
    if(bell > time){
        time = bell;
    }
    cout << time;
    return 0;
}