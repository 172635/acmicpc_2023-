#include <bits/stdc++.h>

using namespace std;

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string st;
    cin >> st;
    vector<int> _cs(6);
    int x1, x2;
    for(int i=0;i<n/2;i++){
        x1 = st[i];
        x2 = st[n-i-1];
        if(x1 > x2){
            int temp = x2;
            x2 = x1;
            x1 = temp;
        }
        if(x1 == '2'){
            if(x2 == '2'){
                _cs[0] ++;
            }else if(x2 == '3'){
                _cs[1] ++;
            }else{
                _cs[2] ++;
            }
        }else if(x1 == '3'){
            if(x2 == '3'){
                _cs[3] ++;
            }else{
                _cs[4] ++;
            }
        }else{
            _cs[5] ++;
        }
    }
    int bt = _cs[0] + _cs[4];
    cout << bt*2 << '\n';
    for(int i=0;i<k;i++){
        if(_cs[1] > 0 && _cs[2] > 0){
            _cs[1] --;
            _cs[2] --;
            _cs[0] ++;
            _cs[4] ++;
            bt += 2;
        }else if(_cs[3] > 0 && _cs[5] > 0){
            _cs[3] --;
            _cs[5] --;
            _cs[4] += 2;
            bt += 2;
        }else if(_cs[1] > 1){
            _cs[1] -= 2;
            _cs[0] ++;
            _cs[3] ++;
            bt ++;
        }else if(_cs[2] > 1){
            _cs[2] -= 2;
            _cs[0] ++;
            _cs[5] ++;
            bt ++;
        }else if(_cs[1] > 0 && _cs[5] > 0){
            _cs[1] --;
            _cs[5] --;
            _cs[2] ++;
            _cs[4] ++;
            bt ++;
        }else if(_cs[2] > 0 && _cs[3] > 0){
            _cs[2] --;
            _cs[3] --;
            _cs[1] ++;
            _cs[4] ++;
            bt ++;
        }
        cout << bt*2 << '\n';
    }
    return 0;
}