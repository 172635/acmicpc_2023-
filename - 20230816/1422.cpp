#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int k, n;
    scanf("%d %d", &k, &n);
    vector<pair<double,pair<int,int>>> pr;
    vector<pair<double,int>> numar[11];
    for(int i=0;i<k;i++){
        int x;
        scanf("%d", &x);
        double xt = x;
        for(int j=1;j<11;j++){
            if(xt < 10){
                double pl = 0;
                for(int tt = 0; tt<(10/j)+1; tt++){
                    pl += xt;
                    for(int t=0;t<j;t++){
                        pl /= 10;
                    }
                }
                numar[j].push_back({xt+pl, -x});
                pr.push_back({xt+pl, {j, -x}});
                break;
            }
            xt /= 10;
        }
    }
    int mnar = 10;
    int mnari = 10;
    while(mnar > 0){
        if(numar[mnar].size() == 0){
            mnar --;
            continue;
        }
        mnari = numar[mnar].size() - 1;
        sort(numar[mnar].begin(), numar[mnar].end());
        break;
    }
    for(int i=0;i<n-k;i++){
        pr.push_back({numar[mnar][mnari].first , {mnar, numar[mnar][mnari].second}});
    }
    sort(pr.begin(), pr.end());
    for(int i=n-1;i>=0;i--){
        printf("%d", -pr[i].second.second);
    }
    printf("\n");
    return 0;
}