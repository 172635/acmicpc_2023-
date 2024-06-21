#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long int w = 0;
        long long int b = 0;
        int mod = 0;
        for(int idx = s.size()-1; idx>=0; idx--){
            if(mod == 0 && s[idx] == '.'){
                continue;
            }else if(mod >= 0 && s[idx] == 'W'){
                mod ++;
            }else if(mod <= 0 && s[idx] == 'B'){
                mod --;
            }else if(mod > 0 && s[idx] == '.'){
                w += mod;
            }else if(mod < 0 && s[idx] == '.'){
                b += (-mod);
            }else{
                mod = 0;
            }
        }
        if(w > b){
            cout << "WHITE\n";
        }else{
            cout << "BLACK\n";
        }
    }
    return 0;
}