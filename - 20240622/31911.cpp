#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    long long int k;
    cin >> n >> k >> m;
    int val[200];
    val[45] = 0;
    val[91] = 1;
    val[93] = 2;
    for(int i='a';i<='z';i++){
        val[i] = 3 + i - 'a';
    }
    char val_re[200];
    val_re[0] = '-';
    val_re[1] = '[';
    val_re[2] = ']';
    for(int i=3;i<=3+'z'-'a';i++){
        val_re[i] = 'a' + i-3;
    }
    int num[31][31];
    for(int i=0;i<31;i++){
        for(int j=0;j<31;j++){
            num[i][j] = 0;
        }
    }
    while(n--){
        string train;
        cin >> train;
        for(int i=0;i<train.length()-1;i++){
            num[val[train[i]]][val[train[i+1]]] ++;
        }
    }
    int next[31];
    for(int i=0;i<31;i++){
        int nen = 0;
        next[i] = 0;
        for(int j=0;j<31;j++){
            if(nen < num[i][j]){
                nen = num[i][j];
                next[i] = j;
            }
        }
    }

    vector<int> cycle;
    vector<int> start;
    int cycle_check[31];
    for(int i=0;i<31;i++){
        cycle_check[i] = -1;
    }
    int now = 1;
    start.push_back(now);
    cycle_check[now] = 0;
    while(true){
        now = next[now];
        if(cycle_check[now] != -1){
            for(int i=cycle_check[now];i<start.size();i++){
                cycle.push_back(start[i]);
            }
            break;
        }
        cycle_check[now] = start.size();
        start.push_back(now);
        if(now == 2){
            break;
        }
    }
    k --;
    while(k < start.size() && m > 0){
        cout << val_re[start[k]];
        k++;
        m--;
    }
    k -= start.size();
    if(cycle.size() == 0){
        while(m--){
            cout << ".";
        }
    }else{
        k %= cycle.size();
        while(m > 0){
            cout << val_re[cycle[k]];
            m --;
            k ++;
            if(k == cycle.size()){
                k = 0;
            }
        }
    }
    return 0;
}