#include <bits/stdc++.h>

using namespace std;

int main(){
    string inp1, inp2;
    cin >> inp1;
    cin >> inp2;
    int sec1 = ((inp1[0] - 48) * 10 + (inp1[1] - 48)) * 3600 + ((inp1[3] - 48) * 10 + (inp1[4] - 48)) * 60 + ((inp1[6] - 48) * 10 + (inp1[7] - 48));
    int sec2 = ((inp2[0] - 48) * 10 + (inp2[1] - 48)) * 3600 + ((inp2[3] - 48) * 10 + (inp2[4] - 48)) * 60 + ((inp2[6] - 48) * 10 + (inp2[7] - 48));
    int dif = 0;
    if(sec1 <= sec2){
        dif = sec2 - sec1;
    }else{
        dif = 86400 - (sec1 - sec2);
    }
    
    cout << dif / 36000 << dif % 36000 / 3600 << ":" << dif % 3600 / 600 << dif % 600 / 60 << ":" << dif % 60 / 10 << dif % 10 << endl;
    return 0; 
}