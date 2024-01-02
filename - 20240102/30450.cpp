#include <bits/stdc++.h>

using namespace std;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int k, c;
    cin >> k;
    cin >> c;
    int * ticket = new int[k];
    for(int i=0;i<k;i++){
        cin >> ticket[i];
    }
    vector<int> lot;
    for(int i=k-1;i>=0;i--){
        if(i < k-1 && ticket[i+1] != ticket[i]){
            lot.push_back(ticket[i+1]);
        }
        for(int j=c;j>=1;j--){
            if(ticket[i] != j){
                lot.push_back(j);
            }
        }
        if(i != 0){
            lot.push_back(ticket[i-1]);
        }
    }
    string ans = "";
    for(int i=lot.size()-1;i>0;i--){
        ans = ans += to_string(lot[i]) + " ";
    }
    ans = ans += to_string(lot[0]) + "\n";
    fwrite(ans.c_str(), 1, ans.size(), stdout);
    return 0;
}