#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int tn;
    scanf("%d", &tn);
    for(int ti = 0; ti<tn; ti++){
        int n, m, t;
        scanf("%d %d %d", &n, &m, &t);
        int s, g, h;
        scanf("%d %d %d", &s, &g, &h);
        if(g > h){
            int temp = h;
            h = g;
            g = temp;
        }
        s --;
        g --;
        h --;
        int * dist1 = new int [n];
        vector<pair<int,int>> * link1 = new vector<pair<int,int>> [n];
        int * dist2 = new int [n];
        int * dist2g = new int [n];
        int * dist2h = new int [n];
        vector<pair<int,int>> * link2 = new vector<pair<int,int>> [n];
        int distgh;
        for(int i=0;i<m;i++){
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            a --;
            b --;
            link1[a].push_back({b, d});
            link1[b].push_back({a, d});
            if(a == g && b == h){
                distgh = d;
            }else{
                link2[a].push_back({b, d});
                link2[b].push_back({a, d});
            }
        }
        for(int i=0;i<n;i++){
            dist1[i] = 100000000;
            dist2[i] = 100000000;
            dist2g[i] = 100000000;
            dist2h[i] = 100000000;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, s});
        while(!pq.empty()){
            pair<int,int> nw = pq.top();
            pq.pop();
            int to = nw.second;
            int dist = nw.first;
            if(dist1[to] != 100000000){
                continue;
            }
            dist1[to] = dist;
            for(int i=0;i<link1[to].size();i++){
                pair<int,int> nx = link1[to][i];
                if(dist1[nx.first] == 100000000){
                    pq.push({dist + nx.second, nx.first});
                }
            }
        }
        pq.push({0, s});
        while(!pq.empty()){
            pair<int,int> nw = pq.top();
            pq.pop();
            int to = nw.second;
            int dist = nw.first;
            if(dist2[to] != 100000000){
                continue;
            }
            dist2[to] = dist;
            for(int i=0;i<link2[to].size();i++){
                pair<int,int> nx = link2[to][i];
                if(dist2[nx.first] == 100000000){
                    pq.push({dist + nx.second, nx.first});
                }
            }
        }
        pq.push({0, g});
        while(!pq.empty()){
            pair<int,int> nw = pq.top();
            pq.pop();
            int to = nw.second;
            int dist = nw.first;
            if(dist2g[to] != 100000000){
                continue;
            }
            dist2g[to] = dist;
            for(int i=0;i<link2[to].size();i++){
                pair<int,int> nx = link2[to][i];
                if(dist2g[nx.first] == 100000000){
                    pq.push({dist + nx.second, nx.first});
                }
            }
        }
        pq.push({0, h});
        while(!pq.empty()){
            pair<int,int> nw = pq.top();
            pq.pop();
            int to = nw.second;
            int dist = nw.first;
            if(dist2h[to] != 100000000){
                continue;
            }
            dist2h[to] = dist;
            for(int i=0;i<link2[to].size();i++){
                pair<int,int> nx = link2[to][i];
                if(dist2h[nx.first] == 100000000){
                    pq.push({dist + nx.second, nx.first});
                }
            }
        }
        vector<int> canBe;
        for(int i=0;i<t;i++){
            int x;
            scanf("%d", &x);
            x --;
            if(dist1[x] == dist2g[x]+dist2[h]+distgh){
                canBe.push_back(x+1);
            }else if(dist1[x] == dist2h[x]+dist2[g]+distgh){
                canBe.push_back(x+1);
            }
        }
        sort(canBe.begin(), canBe.end());
        for(int i=0;i<canBe.size();i++){
            printf("%d ", canBe[i]);
        }
        printf("\n");
    }
    return 0;
}