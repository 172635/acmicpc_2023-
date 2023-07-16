#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int ToIn[101][101][101]; //tomato_info
int Day[101][101][101];

int main(){
    int n, m, h;
    scanf("%d %d %d", &n, &m, &h);
    for(int z = 1; z <= h; z++){
        for(int y = 1; y <= m; y++){
            for(int x = 1; x <= n; x++){
                int a;
                scanf("%d", &a);
                ToIn[x][y][z] = a;
            }
        }
    }
    queue<pair<int,pair<int,int>>> tile_now;
    for(int z = 1; z <= h; z++){
        for(int y = 1; y <= m; y++){
            for(int x = 1; x <= n; x++){
                if(ToIn[x][y][z] == 1){
                    tile_now.push({x, {y, z}});
                }
            }
        }
    }
    while(!tile_now.empty()){
        int now_x = tile_now.front().first;
        int now_y = tile_now.front().second.first;
        int now_z = tile_now.front().second.second;
        tile_now.pop();
        for(int d=0;d<6;d++){
            int next_x = now_x + dx[d];
            int next_y = now_y + dy[d];
            int next_z = now_z + dz[d];
            if(next_x > 0 && next_x < n+1 && next_y > 0 && next_y < m+1 && next_z > 0 && next_z < h+1 && ToIn[next_x][next_y][next_z] == 0){
                if(Day[next_x][next_y][next_z] == 0 || Day[next_x][next_y][next_z] > Day[now_x][now_y][now_z] + 1){
                    Day[next_x][next_y][next_z] = Day[now_x][now_y][now_z] + 1;
                    tile_now.push({next_x, {next_y, next_z}});
                }
            }
        }
    }
    int max_day = 0;
    int check_none = 0;
    for(int x = 1; x <= n; x++){
        if(check_none == 1){
            break;
        }
        for(int y = 1; y <= m; y++){
            if(check_none == 1){
                break;
            }
            for(int z = 1; z <= h; z++){
                if(Day[x][y][z] > max_day){
                    max_day = Day[x][y][z];
                }else if(Day[x][y][z] == 0 && ToIn[x][y][z] == 0){
                    max_day = -1;
                    check_none = 1;
                    break;
                }
            }
        }
    }
    printf("%d", max_day);
    return 0;
}
