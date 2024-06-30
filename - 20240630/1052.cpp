#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> n2;
    int one = 0;
    while(n > 0){
        n2.push_back(n % 2);
        if(n % 2 == 1){one ++;}
        n /= 2;
    }
    if(one <= k){
        cout << 0 << "\n";
    }else{
        one -= k;
        int sum = 0;
        for(int idx=0;idx<n2.size();idx++){
            if(n2[idx] == 2){
                one --;
                if(idx != n2.size()-1){n2[idx+1] ++;}
                else{n2.push_back(1);}
                n2[idx] = 0;
            }else if(n2[idx] == 1){
                if(one > 0){
                    n2[idx+1] ++;
                    n2[idx] = 0;
                    sum += 1 << idx;
                }
            }
        }
        cout << sum << "\n";
    }
    return 0;
}