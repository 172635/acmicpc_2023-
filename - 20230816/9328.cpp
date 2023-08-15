#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int tc=0;tc<t;tc++){
        int h, w;
        scanf("%d %d", &h, &w);
        int ** map = new int * [h+2];
        for(int i=0;i<h+2;i++){
            map[i] = new int [w+2];
            if(i == 0 || i == h+1){
                for(int j=0;j<w+2;j++){
                    map[i][j] = '.';
                }
                continue;
            }
            map[i][0] = '.';
            map[i][w+1] = '.';
            char * rl = new char [w+1];
            scanf("%s", rl);
            for(int j=1;j<w+1;j++){
                map[i][j] = rl[j-1];
            }
        }
        int * keyC = new int [26];
        for(int i=0;i<26;i++){
            keyC[i] = 0;
        }
        char alkey[30];
        scanf("%s", alkey);
        if(alkey[0] != '0'){
            for(int i=0;alkey[i] != '\0'; i++){
                keyC[alkey[i] - 'a'] = 1;
            }
        }
        queue<pair<int,int>> q;
        q.push({0, 0});
        map[0][0] = '*';
        vector<pair<int,int>> * door = new vector<pair<int,int>> [26];
        int reward = 0;
        int mh[4] = {0, 0, -1, 1};
        int mw[4] = {-1, 1, 0, 0};
        while(!q.empty()){
            pair<int,int> hw = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nh = hw.first + mh[i];
                int nw = hw.second + mw[i];
                if(nh < 0 || nh >= h+2 || nw < 0 || nw >= w+2){
                    continue;
                }
                if(map[nh][nw] == '.'){
                    q.push({nh, nw});
                    map[nh][nw] = '*';
                }else if(map[nh][nw] == '$'){
                    reward ++;
                    q.push({nh, nw});
                    map[nh][nw] = '*';
                }else if(map[nh][nw] >= 'a' && map[nh][nw] <= 'z'){
                    int alpha = map[nh][nw] - 'a';
                    keyC[alpha] = 1;
                    for(int k=0;k<door[alpha].size();k++){
                        q.push(door[alpha][k]);
                    }
                    door[alpha].clear();
                    q.push({nh, nw});
                    map[nh][nw] = '*';
                }else if(map[nh][nw] >= 'A' && map[nh][nw] <= 'Z'){
                    int alpha = map[nh][nw] - 'A';
                    if(keyC[alpha] == 0){
                        door[alpha].push_back({nh, nw});
                    }else{
                        q.push({nh, nw});
                    }
                    map[nh][nw] = '*';
                }
            }
        }
        printf("%d\n", reward);
    }
    return 0;
}