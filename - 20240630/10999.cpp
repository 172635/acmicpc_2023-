#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<long long int> part[21];
    for(int i=0;i<n;i++){
        long long int x;
        cin >> x;
        part[0].push_back(x);
    }
    int h = 0;
    for(int i=1;i<21;i++){
        for(int j=0;j<part[i-1].size()/2;j++){
            part[i].push_back(part[i-1][j*2] + part[i-1][j*2+1]);
        }
        if(part[i].size() > 0){
            h = i;
        }
    }
    vector<pair<pair<int,int>, long long int>> add;
    for(int __i=0;__i<m+k;__i++){
        int a, b, c;
        cin >> a;
        if(a == 1){
            long long int d;
            cin >> b >> c >> d;
            b--;
            c--;
            add.push_back({{b,c}, d});
        }else if(a == 2){
            cin >> b >> c;
            b--;
            c--;
            long long int sum = 0;
            if(b == c){
                sum += part[0][b];
                for(int i=0;i<add.size();i++){
                    if(add[i].first.first <= b && add[i].first.second >= b){
                        sum += add[i].second;
                    }
                }
                cout << sum << "\n";
            }else{
                int _b = b;
                int _c = c;
                for(int i=0;i<=h;i++){
                    if(_b+1 == _c){break;}
                    if(_b % 2 == 0){
                        sum += part[i][_b + 1];
                    }
                    if(_c % 2 == 1){
                        sum += part[i][_c - 1];
                    }
                    _b /= 2;
                    _c /= 2;
                }
                sum += part[0][b];
                sum += part[0][c];

                for(int i=0;i<add.size();i++){
                    int _b = add[i].first.first;
                    int _c = add[i].first.second;
                    if(c < _b || b > _c){
                        continue;
                    }
                    int range = (c < _c ? c : _c) - (b > _b ? b : _b) + 1;
                    sum += range * add[i].second;
                }
                cout << sum << "\n";
            }
        }
    }
    return 0;
}