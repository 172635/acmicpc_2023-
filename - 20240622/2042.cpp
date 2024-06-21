#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long int> num;
    vector<long long int> partS;
    for(int i=0;i<n;i++){
        long long int x = 1;
        cin >> x;
        num.push_back(x);
        if(i%1000 == 0){
            partS.push_back(x);
        }else{
            partS[i/1000] += x;
        }
    }
    for(int i=0;i<m+k;i++){
        long long int a, b, c;
        cin >> a >> b >> c;
        b--;
        if(a == 1){
            partS[b/1000] += c - num[b];
            num[b] = c;
        }else if(a == 2){
            long long int sum = 0;
            c--;
            if(b/1000 == c/1000){
                for(int j=b;j<=c;j++){
                    sum += num[j];
                }
                cout << sum << "\n";
            }else{
                for(int j=b;j<(b/1000+1)*1000;j++){
                    sum += num[j];
                }
                for(int j=(c/1000)*1000;j<=c;j++){
                    sum += num[j];
                }
                for(int j=b/1000+1; j<c/1000; j++){
                    sum += partS[j];
                }
                cout << sum << "\n";
            }
        }
    }
    return 0;
}