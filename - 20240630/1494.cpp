#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    long long int first,second;
    int n;
    cin >> first >> second >> n;
    vector<pair<long long int,pair<long long int, long long int>>> v;
    v.push_back({first, {-1,0}});
    v.push_back({second, {first, 0}});
    int size = 2;
    while(v[v.size()-1].first != 0){
        first = v[v.size()-1].second.first;
        second = v[v.size()-1].first;
        if(first >= second){
            v.push_back({first % second, {first/second % 2 == 0 ? (second + first % second):(second), first / second}});
        }else{
            v.push_back({second - first, {second, 0}});
        }
    }

    while(n--){
        long long int x;
        cin >> x;
        long long int nnow = 0;
        for(int i=0;i<v.size();i++){
            //cout << i << " : " << v[i-2].first << " " << v[i-1].first << " " << v[i].first << "\n";
            nnow = 0;
            pair<long long int, pair<long long int, long long int>> now = v[i];
            if(now.second.second == 0){
                nnow = 1;
            }else if(now.second.second % 2 == 0){
                nnow = 2 + (now.second.second-1) / 2 * 3;
            }else{
                nnow = 1 + now.second.second / 2 * 3;
            }
            if(nnow > x){
                if(nnow == 1){cout << now.first << "\n";}
                else if(x % 3 == 2){
                    cout << v[i-1].first << "\n";
                }else if(x % 3 == 0){
                    cout << v[i-1].second.first - v[i-1].first * (x / 3 * 2 + 1) << "\n";
                }else{
                    cout << v[i-1].second.first - v[i-1].first * (x / 3 * 2 + 2) << "\n";
                }
                x -= nnow;
                break;
            }
            x -= nnow;
        }
        if(x >= 0){
            if(x % 3 == 2){cout << "0\n";}
            else{cout << v[v.size()-1].second.first << "\n";}
        }
    }
    return 0;
}