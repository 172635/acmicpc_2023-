#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int,int>> record;
    vector<int> * soc = new vector<int> [n+1]; // size of color
    vector<int> * sumsoc = new vector<int> [n+1]; // sum size of color
    for(int i=0;i<n;i++){
        int c, s;
        scanf("%d %d", &c, &s);
        record.push_back({c, s});
        soc[c].push_back(s);
        soc[0].push_back(s);
    }
    for(int i=0;i<=n;i++){
        soc[i].push_back(0);
        sort(soc[i].begin(), soc[i].end());
        for(int j=0;j<soc[i].size();j++){
            if(j == 0){
                sumsoc[i].push_back(soc[i][j]);
                continue;
            }
            sumsoc[i].push_back(sumsoc[i][j-1]+soc[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        int c = record[i].first;
        int s = record[i].second;
        int zif = 0;
        int zit = soc[0].size();
        while(zif != zit - 1){
            int half = (zif + zit) /2;
            if(soc[0][half] >= s){
                zit = half;
            }else{
                zif = half;
            }
        }
        int cif = 0;
        int cit = soc[c].size();
        while(cif != cit - 1){
            int half = (cif + cit) /2;
            if(soc[c][half] >= s){
                cit = half;
            }else{
                cif = half;
            }
        }
        printf("%d\n", sumsoc[0][zif]-sumsoc[c][cif]);
    }
    return 0;
}