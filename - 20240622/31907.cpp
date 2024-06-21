#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int k;
    cin >> k;
    for(int i=0;i<3*k;i++){
        for(int j=0;j<4*k;j++){
            if(i < k && j < k){
                cout << "G";
            }else if(i >= k && i < 2*k && j >= k && j < 2*k){
                cout << "I";
            }else if(i >= 2*k && j >= 2*k && j < 3*k){
                cout << "S";
            }else if(i >= k && i < 2*k && j >= 3*k){
                cout << "T";
            }else{
                cout << ".";
            }
        }
        cout << "\n";
    }
    return 0;
}