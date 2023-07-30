#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int numcost[10];
    for(int i=0;i<n;i++){
        scanf("%d", &numcost[i]);
    }
    int m;
    scanf("%d", &m);

    if(n == 1){
        printf("0\n");
        return 0;
    }
    
    vector<pair<int,int>> mini;
    for(int i=0;i<n;i++){
        mini.push_back({numcost[i], i});
    }
    sort(mini.begin(), mini.end());
    int maxnum = 0;
    int _maxsum = 0;
    if(mini[0].second == 0){
        if(m >= mini[1].first){
            maxnum = 1 + (m-mini[1].first) / mini[0].first;
        }else{
            maxnum = 1;
        }
    }else{
        maxnum = m / mini[0].first;
    }
    vector<int> room;
    int num = n - 1;
    int maxsum = 0;
    while(maxnum > 0){
        for(int i=num; i>=0; i--){
            int _maxs = maxsum + numcost[i];
            int _maxn = maxnum - 1;
            if(_maxn * mini[0].first + _maxs <= m){
                maxsum += numcost[i];
                maxnum --;
                room.push_back(i);
                num = i;
                break;
            }
        }
    }
    for(int i=0;i<room.size();i++){
        printf("%d", room[i]);
    }
    printf("\n");
    return 0;
}