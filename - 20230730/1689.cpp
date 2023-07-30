#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int Max = 0;
    int Now = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pqf;
    priority_queue<int, vector<int>, greater<int>> pqe;
    for(int i=0;i<n;i++){
        int s, e;
        scanf("%d %d", &s, &e);
        pqf.push({s, e});
    }
    int x = pqf.top().first;
    while(!pqf.empty()){
        pair<int,int> nw = pqf.top();
        pqf.pop();
        x = nw.first;
        pqe.push(nw.second);
        Now ++;
        while(!pqe.empty()){
            if(pqe.top() > x){
                break;
            }
            pqe.pop();
            Now --;
        }
        if(Max < Now){
            Max = Now;
        }
    }
    printf("%d\n", Max);
    return 0;
}