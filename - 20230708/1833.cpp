#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int ** fi = new int * [n];
    int lengN = 0;
    int numN = 0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    int * check = new int[n];
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
        fi[i] = new int [n];
        check[i] = 0;
        for(int j=0;j<n;j++){
            int x;
            scanf("%d", &x);
            if(x < 0){
                if(i > j){
                    lengN += (- x);
                }
                x = 0;
            }
            fi[i][j] = x;
        }
    }

    pq.push({0, {0, 0}});
    while(numN < n-1){
        if(pq.empty()){
            break;
        }
        pair<int, pair<int, int>> nw = pq.top();
        pq.pop();
        if(check[nw.second.second] == 1){
            continue;
        }
        check[nw.second.second] = 1;
        if(nw.first != 0){
            numN ++;
            lengN += nw.first;
            if(nw.second.second != nw.second.first){
                v.push_back({nw.second.first, nw.second.second});
            }
        }
        for(int i=0;i<n;i++){
            if(i == nw.second.second || check[i] == 1){
                continue;
            }
            pq.push({fi[i][nw.second.second], {nw.second.second, i}});
        }
    }
    printf("%d %d\n", lengN, numN);
    for(int i=0;i<v.size();i++){
        printf("%d %d\n", v[i].first + 1, v[i].second + 1);
    }
    return 0;
}