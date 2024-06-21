#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    deque<int> inp;
    while(n--){
        int x;
        cin >> x;
        inp.push_back(x);
    }
    sort(inp.begin(), inp.end());
    vector<int> oup;
    while(!inp.empty()){
        if(inp.front() + 1 == inp.back()){
            while(inp.size() > 1 && inp[inp.size()-1] == inp[inp.size()-2]){
                oup.push_back(inp.back());
                inp.pop_back();
            }
            oup.push_back(inp.back());
            inp.pop_back();
        }else if(oup.size() > 0 && oup[oup.size()-1] +1 == inp.front()){
            int c = 0;
            while(inp[c] == oup[oup.size()-1]+1){
                c ++;
            }
            oup.push_back(inp[c]);
            inp.erase(inp.begin() + c);
        }else{
            while(inp.size() > 1 && inp[0] == inp[1]){
                oup.push_back(inp.front());
                inp.pop_front();
            }
            oup.push_back(inp.front());
            inp.pop_front();
        }
    }
    for(int i=0;i<oup.size();i++){
        cout << oup[i] << " ";
    }
    return 0;
}