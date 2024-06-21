#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int> candy[21];
    for(int i=0;i<1048576;i++){
        candy[0].push_back(0);
    }
    for(int i=1;i<21;i++){
        for(int j=0;j<candy[i-1].size()/2;j++){
            candy[i].push_back(candy[i-1][j*2] + candy[i-1][j*2+1]);
        }
    }

    int n;
    cin >> n;
    while(n--){
        int a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b;
            int h = 20, i = 0;
            while(h>0){
                if(candy[h-1][i*2] < b){
                    b -= candy[h-1][i*2];
                    h --;
                    i = i*2+1;
                }else{
                    h --;
                    i = i*2;
                }
            }
            cout << i+1 << "\n";
            b = i;
            for(int i=0;i<21;i++){
                if(b >= candy[i].size()){break;}
                candy[i][b] --;
                b /= 2;
            }
        }else{
            cin >> b >> c;
            b--;
            for(int i=0;i<21;i++){
                if(b >= candy[i].size()){break;}
                candy[i][b] += c;
                b /= 2;
            }
        }
    }
    return 0;
}