#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    unordered_map<string, vector<string>> um;
    while(n--){
        string name;
        string ring;
        cin >> name >> ring;
        if(ring == "-"){
            continue;
        }
        if(um.find(ring) == um.end()){
            vector<string> v;
            v.push_back(name);
            um[ring] = v;
        }else{
            um[ring].push_back(name);
        }
    }
    vector<pair<string, string>> vp;
    for(const auto& n : um){
        if(n.second.size() == 2){
            vp.push_back(make_pair(n.second[0], n.second[1]));
        }
    }
    cout << vp.size() << "\n";
    for(int i=0;i<vp.size();i++){
        cout << vp[i].first << " " << vp[i].second << "\n";
    }
    return 0;
}