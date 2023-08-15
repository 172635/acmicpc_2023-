#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> * dw = new vector<int> [n];
    int * up = new int [n];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        up[i] = x;
        if(x != -1){
            dw[x].push_back(i);
        }
    }
    int leafn = 0;
    for(int i=0;i<n;i++){
        if(dw[i].size() == 0){
            leafn ++;
        }
    }
    int delx;
    scanf("%d", &delx);
    if(up[delx] != -1 && dw[up[delx]].size() == 1){
        leafn ++;
    }
    queue<int> delq;
    delq.push(delx);
    while(!delq.empty()){
        int fr = delq.front();
        delq.pop();
        if(dw[fr].size() == 0){
            leafn --;
        }else{
            for(int i=0;i<dw[fr].size();i++){
                delq.push(dw[fr][i]);
            }
        }
    }
    printf("%d\n", leafn);
    return 0;
}