#include <bits/stdc++.h>

using namespace std;

vector<int> hist;
int maxsq(int, int);
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        hist.push_back(x);
    }
    cout << maxsq(0, n-1) << endl;
    return 0;
}
int maxsq(int i, int e){
    if(e == i){
        return hist[i];
    }else if(e == i+1){
        return max(max(hist[i], hist[e]), 2*min(hist[i], hist[e]));
    }
    int m = (i+e)/2;
    int sq = max(maxsq(i, m), maxsq(m+1, e));
    
    int height = hist[m];
    int mi = m, me = m;
    sq = max(sq, hist[m]);
    while(mi != i || me != e){
        if(mi == i){
            me ++;
            if(height > hist[me]){
                height = hist[me];
            }
        }else if(me == e){
            mi --;
            if(height > hist[mi]){
                height = hist[mi];
            }
        }else{
            if(hist[mi-1] < hist[me+1]){
                me ++;
                if(height > hist[me]){
                    height = hist[me];
                }
            }else{
                mi --;
                if(height > hist[mi]){
                    height = hist[mi];
                }
            }
        }
        sq = max(sq, height * (me - mi + 1));
    }
    return sq;
}