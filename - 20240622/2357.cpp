#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int pow2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};
    int n, m, x, a, b;
    cin >> n >> m;
    int npow = 1;
    while(pow2[npow-1] < n){npow++;}
    vector<pair<int,int>> * mm = new vector<pair<int,int>> [npow];
    for(int i=0;i<n;i++){
        cin >> x;
        mm[0].push_back({x, x});
    }
    for(int i=1;i<npow;i++){
        for(int j=0;j<mm[i-1].size()/2;j++){
            mm[i].push_back({max<int>(mm[i-1][j*2].first, mm[i-1][j*2+1].first), -max<int>(-mm[i-1][j*2].second, -mm[i-1][j*2+1].second)});
        }
        if(mm[i-1].size() % 2 == 1){
            mm[i].push_back(mm[i-1][mm[i-1].size()-1]);
        }
        //cout << "-------------------\n" << i-1 << "\n";
        //for(auto a : mm[i-1]){cout << a.first << " " << a.second << "\n";}
    }
    while(m--){
        cin >> a >> b;
        a--;
        b--;
        if(a == b){
            cout << mm[0][a].first << " " << mm[0][a].second << "\n";
            continue;
        }
        int high = npow - 1;
        int hin = pow2[high];
        while(high >= 0){
            if(a < hin && b < hin){
                high --;
                hin -= pow2[high];
            }else if(a >= hin && b >= hin){
                high --;
                hin += pow2[high];
            }else{
                break;
            }
        }
        vector<int> a2, b2;
        int _a = a;
        int _b = b;
        for(int i=0;i<high;i++){
            a2.push_back(_a % 2);
            b2.push_back(_b % 2);
            _a /= 2;
            _b /= 2;
        }
        int _min = 1500000000;
        int _max = 0;
        for(int i=0;i<high;i++){
            if(a2[i] == 0){
                pair<int,int> nw = mm[i][(a - a % pow2[i] + pow2[i]) / pow2[i]];
                if(_max < nw.first){
                    _max = nw.first;
                }
                if(_min > nw.second){
                    _min = nw.second;
                }
            }
            if(b2[i] == 1){
                pair<int,int> nw = mm[i][(b - b % pow2[i] - pow2[i]) / pow2[i]];
                if(_max < nw.first){
                    _max = nw.first;
                }
                if(_min > nw.second){
                    _min = nw.second;
                }
            }
        }
        if(_max < mm[0][a].first){
            _max = mm[0][a].first;
        }
        if(_min > mm[0][a].second){
            _min = mm[0][a].second;
        }
        if(_max < mm[0][b].first){
            _max = mm[0][b].first;
        }
        if(_min > mm[0][b].second){
            _min = mm[0][b].second;
        }
        cout << _min << " " << _max << "\n";
    }
    return 0;
}