#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long int K;
    cin >> K;
    int ** _map = new int*[50];
    for(int i = 0;i<50;i++){
        _map[i] = new int[50];
        for(int j=0;j<50;j++){
            if(i == 49 || j == 49){
                _map[i][j] = 0;
            }else{
                _map[i][j] = 1;
            }
        }
    }
    long long int * per = new long long int[10];
    per[0] = 1;
    for(int i=1;i<10;i++){
        per[i] = per[i-1] * 70;
    }
    int * rest = new int[10];
    for(int i=9;i>=0;i--){
        rest[i] = K / per[i];
        K %= per[i];
    }
    vector<pair<int,int>> n15[15];
    n15[1].push_back({0,0});
    n15[1].push_back({0,1});
    n15[1].push_back({0,2});
    n15[2].push_back({0,0});
    n15[2].push_back({0,1});
    n15[2].push_back({0,2});
    n15[2].push_back({1,2});
    n15[3].push_back({0,0});
    n15[3].push_back({0,1});
    n15[3].push_back({0,2});
    n15[3].push_back({1,2});
    n15[3].push_back({2,2});
    n15[4].push_back({0,0});
    n15[4].push_back({0,1});
    n15[4].push_back({0,2});
    n15[4].push_back({1,2});
    n15[4].push_back({2,2});
    n15[4].push_back({3,2});
    n15[5].push_back({0,0});
    n15[5].push_back({0,1});
    n15[5].push_back({0,2});
    n15[5].push_back({1,2});
    n15[5].push_back({2,2});
    n15[5].push_back({3,2});
    n15[5].push_back({1,0});
    n15[5].push_back({2,0});
    n15[5].push_back({3,0});
    n15[5].push_back({3,1});
    n15[6].push_back({0,0});
    n15[6].push_back({1,0});
    n15[6].push_back({2,0});
    n15[6].push_back({0,1});
    n15[6].push_back({1,1});
    n15[6].push_back({2,1});
    n15[6].push_back({2,2});
    n15[6].push_back({3,2});
    n15[7].push_back({0,0});
    n15[7].push_back({1,0});
    n15[7].push_back({2,0});
    n15[7].push_back({0,1});
    n15[7].push_back({1,1});
    n15[7].push_back({2,1});
    n15[7].push_back({0,2});
    n15[7].push_back({2,2});
    n15[7].push_back({3,2});
    n15[9].push_back({0,0});
    n15[9].push_back({1,0});
    n15[9].push_back({2,0});
    n15[9].push_back({0,1});
    n15[9].push_back({1,1});
    n15[9].push_back({2,1});
    n15[9].push_back({3,1});
    n15[9].push_back({2,2});
    n15[9].push_back({3,2});
    n15[10].push_back({0,0});
    n15[10].push_back({1,0});
    n15[10].push_back({2,0});
    n15[10].push_back({0,1});
    n15[10].push_back({1,1});
    n15[10].push_back({2,1});
    n15[10].push_back({3,1});
    n15[10].push_back({0,2});
    n15[10].push_back({2,2});
    n15[10].push_back({3,2});
    n15[11].push_back({0,0});
    n15[11].push_back({1,0});
    n15[11].push_back({2,0});
    n15[11].push_back({3,0});
    n15[11].push_back({0,1});
    n15[11].push_back({1,1});
    n15[11].push_back({2,1});
    n15[11].push_back({3,1});
    n15[11].push_back({0,2});
    n15[11].push_back({2,2});
    n15[11].push_back({3,2});
    n15[12].push_back({0,0});
    n15[12].push_back({1,0});
    n15[12].push_back({0,1});
    n15[12].push_back({1,1});
    n15[12].push_back({2,1});
    n15[12].push_back({3,1});
    n15[12].push_back({1,2});
    n15[12].push_back({2,2});
    n15[12].push_back({3,2});
    n15[14].push_back({0,0});
    n15[14].push_back({1,0});
    n15[14].push_back({0,1});
    n15[14].push_back({1,1});
    n15[14].push_back({2,1});
    n15[14].push_back({0,2});
    n15[14].push_back({1,2});
    n15[14].push_back({2,2});
    n15[14].push_back({3,2});

    for(int i=0;i<9;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                _map[i*5+j][i*5+k] = 0;
            }
        }
        _map[i*5+4][i*5+5] = 0;
        for(int j=i*5+5;j<46;j++){
            _map[i*5][j] = 0;
            _map[j][i*5] = 0;
            _map[j][i*5+2] = 0;
        }
        int x, y;
        x = rest[i] / 15;
        y = rest[i] % 15;

        if(x > 0){
            for(int j=0;j<3;j++){
                _map[46+j][i*5+2] = 0;
            }
            for(int j=1;j<x;j++){
                _map[49-j][i*5+3] = 0;
            }
        }
        if(y > 0){
            if(y == 8 || y == 13){
                y --;
                for(int j=0;j<3;j++){
                    _map[46+j][i*5] = 0;
                }
            }
            for(int j=0;j<n15[y].size();j++){
                _map[i*5+n15[y][j].first][46+n15[y][j].second] = 0;
            }
        }
    }

    vector<pair<int,int>> n25[25];
    n25[1].push_back({1,0});
    n25[1].push_back({2,0});
    n25[1].push_back({3,0});
    n25[1].push_back({1,1});
    n25[1].push_back({2,1});
    n25[1].push_back({3,1});
    n25[1].push_back({1,2});
    n25[1].push_back({2,2});
    n25[1].push_back({3,2});
    n25[1].push_back({1,3});
    n25[1].push_back({2,3});
    n25[1].push_back({3,3});
    n25[2].push_back({1,1});
    n25[2].push_back({2,1});
    n25[2].push_back({3,1});
    n25[2].push_back({1,2});
    n25[2].push_back({2,2});
    n25[2].push_back({3,2});
    n25[2].push_back({1,3});
    n25[2].push_back({2,3});
    n25[2].push_back({3,3});
    n25[3].push_back({1,1});
    n25[3].push_back({2,1});
    n25[3].push_back({3,1});
    n25[3].push_back({1,2});
    n25[3].push_back({2,2});
    n25[3].push_back({3,2});
    n25[3].push_back({2,3});
    n25[3].push_back({3,3});
    n25[4].push_back({1,1});
    n25[4].push_back({2,1});
    n25[4].push_back({3,1});
    n25[4].push_back({1,2});
    n25[4].push_back({2,2});
    n25[4].push_back({3,2});
    n25[4].push_back({3,3});
    n25[5].push_back({1,1});
    n25[5].push_back({2,1});
    n25[5].push_back({1,2});
    n25[5].push_back({2,2});
    n25[5].push_back({3,2});
    n25[5].push_back({3,3});
    n25[6].push_back({1,1});
    n25[6].push_back({2,1});
    n25[6].push_back({3,1});
    n25[6].push_back({1,2});
    n25[6].push_back({2,2});
    n25[6].push_back({3,2});
    n25[7].push_back({1,1});
    n25[7].push_back({2,1});
    n25[7].push_back({1,2});
    n25[7].push_back({2,2});
    n25[7].push_back({3,2});
    n25[8].push_back({1,1});
    n25[8].push_back({1,2});
    n25[8].push_back({2,2});
    n25[8].push_back({3,2});
    n25[9].push_back({1,0});
    n25[9].push_back({2,0});
    n25[9].push_back({3,0});
    n25[9].push_back({1,1});
    n25[9].push_back({2,1});
    n25[9].push_back({3,1});
    n25[9].push_back({2,2});
    n25[9].push_back({3,2});
    n25[10].push_back({1,1});
    n25[10].push_back({2,1});
    n25[10].push_back({3,1});
    n25[10].push_back({2,2});
    n25[10].push_back({3,2});
    n25[11].push_back({2,1});
    n25[11].push_back({3,2});
    n25[11].push_back({0,3});
    n25[11].push_back({1,3});
    n25[12].push_back({2,0});
    n25[12].push_back({3,0});
    n25[12].push_back({2,1});
    n25[12].push_back({3,1});
    n25[12].push_back({2,2});
    n25[12].push_back({3,2});
    n25[12].push_back({0,3});
    n25[13].push_back({2,1});
    n25[13].push_back({3,1});
    n25[13].push_back({2,2});
    n25[13].push_back({3,2});
    n25[13].push_back({0,3});
    n25[14].push_back({2,1});
    n25[14].push_back({2,2});
    n25[14].push_back({3,2});
    n25[14].push_back({0,3});
    n25[15].push_back({3,0});
    n25[15].push_back({3,1});
    n25[15].push_back({3,2});
    n25[15].push_back({3,3});
    n25[16].push_back({3,1});
    n25[16].push_back({3,2});
    n25[16].push_back({3,3});
    n25[17].push_back({2,0});
    n25[17].push_back({3,0});
    n25[17].push_back({2,1});
    n25[17].push_back({3,1});
    n25[17].push_back({2,2});
    n25[17].push_back({3,2});
    n25[18].push_back({2,1});
    n25[18].push_back({3,1});
    n25[18].push_back({2,2});
    n25[18].push_back({3,2});
    n25[19].push_back({2,1});
    n25[19].push_back({2,2});
    n25[19].push_back({3,2});
    n25[20].push_back({3,2});
    n25[20].push_back({3,3});
    n25[21].push_back({3,0});
    n25[21].push_back({3,1});
    n25[21].push_back({3,3});
    n25[22].push_back({3,1});
    n25[22].push_back({3,3});
    n25[23].push_back({3,0});
    n25[23].push_back({3,1});
    n25[23].push_back({2,3});
    n25[24].push_back({3,1});
    n25[24].push_back({2,3});

    if(rest[9] > 0){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                _map[45+i][45+j] = 0;
            }
        }
        for(int i=0;i<n25[rest[9]].size();i++){
            _map[45+n25[rest[9]][i].first][45+n25[rest[9]][i].second] = 1;
        }
    }

    for(int y=0;y<50;y++){
        for(int x=0;x<50;x++){
            cout << _map[x][y] << ' ';
        }
        cout << '\n';
    }

    return 0;
}