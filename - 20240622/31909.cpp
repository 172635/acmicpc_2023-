#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int num[8];
    for(int i=0;i<8;i++){
        num[i] = i;
    }
    int pow2[8];
    pow2[0] = 1;
    for(int i=1;i<8;i++){
        pow2[i] = pow2[i-1] * 2;
    }
    while(n--){
        int a;
        cin >> a;
        int ai, aj;
        if(a <= 1){
            continue;
        }
        aj = 100;
        for(int i=7;i>=0;i--){
            if(pow2[i] < a){
                ai = i;
                a -= pow2[i];
                break;
            }
        }
        for(int i=ai-1;i>=0;i--){
            if(pow2[i] == a){
                aj = i;
                break;
            }
        }
        if(aj == 100){
            continue;
        }
        int temp = num[ai];
        num[ai] = num[aj];
        num[aj] = temp;
    }
    int k;
    cin >> k;
    cout << num[k];
    return 0;
}