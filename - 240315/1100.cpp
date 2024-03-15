#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int num = 0;
    string line;
    for(int i=0;i<8;i++){
        cin >> line;
        for(int j=i%2;j<8;j+=2){
            if(line[j] == 'F'){
                num ++;
            }
        }
    }
    cout << num;
    return 0;
}