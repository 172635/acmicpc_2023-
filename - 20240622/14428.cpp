#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int npow2 = 0;
    int _n = n;
    while(_n > 0){
        npow2++;
        _n /= 2;
    }
    vector<pair<int,int>> * min = new vector<pair<int,int>> [npow2];
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        min[0].push_back({x,i});
    }
    for(int i=1;i<npow2;i++){
        for(int j=0;j<min[i-1].size()/2;j++){
            if(min[i-1][j*2].first <= min[i-1][j*2+1].first){
                min[i].push_back(min[i-1][j*2]);
            }else{
                min[i].push_back(min[i-1][j*2+1]);
            }
        }
    }

    int m;
    cin >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        if(a == 1){
            min[0][b] = {c, b};
            for(int i=1;i<npow2;i++){
                if(b % 2 == 0 && b == min[i-1].size()-1){break;}
                b/=2;
                if(min[i-1][b*2].first <= min[i-1][b*2+1].first){
                    min[i][b] = min[i-1][b*2];
                }else{
                    min[i][b] = min[i-1][b*2+1];
                }
            }
        }else{
            c--;
            if(b == c){
                cout << b+1 << "\n";
                continue;
            }
            vector<int> b2, c2;
            int _b = b;
            int _c = c;
            for(int i=0;i<npow2;i++){
                b2.push_back(_b % 2);
                c2.push_back(_c % 2);
                _b /= 2;
                _c /= 2;
            }

            int high = npow2;
            int hin = 1<<high;
            while(high > 0){
                if(b < hin && c < hin){
                    high --;
                    hin -= 1<<high;
                }else if(b >= hin && c >= hin){
                    high --;
                    hin += 1<<high;
                }else{
                    break;
                }
            }
            int _min = 1000000001;
            int mindex = 0;
            for(int i=0;i<high;i++){
                if(b2[i] == 0){
                    int bi2 = b/(1<<i)+1;
                    if(_min > min[i][bi2].first){
                        _min = min[i][bi2].first;
                        mindex = min[i][bi2].second;
                    }else if(_min == min[i][bi2].first && mindex > min[i][bi2].second){
                        mindex = min[i][bi2].second;
                    }
                }
                if(c2[i] == 1){
                    int ci2 = c/(1<<i)-1;
                    if(_min > min[i][ci2].first){
                        _min = min[i][ci2].first;
                        mindex = min[i][ci2].second;
                    }else if(_min == min[i][ci2].first && mindex > min[i][ci2].second){
                        mindex = min[i][ci2].second;
                    }
                }
            }
            if(_min > min[0][b].first){
                _min = min[0][b].first;
                mindex = b;
            }else if(_min == min[0][b].first && mindex > b){
                mindex = b;
            }
            if(_min > min[0][c].first){
                _min = min[0][c].first;
                mindex = c;
            }else if(_min == min[0][c].first && mindex > c){
                mindex = c;
            }
            
            cout << mindex+1 << "\n";
        }
    }
    return 0;
}