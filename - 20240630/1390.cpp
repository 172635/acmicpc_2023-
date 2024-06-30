#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int * data = new int[500];
    int case_list[] = {000,001,010,100,011,101,110,022,220,013,310,023,320,200,002,210,012,024,420,120,021,102,201};

    int n;
    cin >> n;
    
    if(n%4 != 0){
        cout << 0 << "\n";
    }else{
        n /= 4;
        n *= 3;
        data[0] = 1;

        while(n--){
            int * temp = new int[500];
            temp[000] = data[011] + data[110] + data[101] + data[023] + data[320] + data[200] + data[002];
            temp[001] = data[000] + data[210] + data[024] + data[201];
            temp[010] = data[000] + data[210] + data[012] + data[102] + data[201];
            temp[100] = data[000] + data[012] + data[420] + data[102];
            temp[011] = data[001] + data[100] + data[220] + data[013];
            temp[101] = data[013] + data[310];
            temp[110] = data[001] + data[100] + data[022] + data[310];
            temp[022] = data[000] + data[120] + data[102];
            temp[220] = data[000] + data[021] + data[201];
            temp[013] = data[000];
            temp[310] = data[000];
            temp[023] = data[001] + data[010];
            temp[320] = data[100] + data[010];
            temp[200] = data[001];
            temp[002] = data[100];
            temp[210] = data[011] + data[101];
            temp[012] = data[110] + data[101];
            temp[024] = data[011];
            temp[420] = data[110];
            temp[120] = data[011] + data[101] + data[200];
            temp[021] = data[110] + data[101] + data[002];
            temp[102] = data[200];
            temp[201] = data[002];

            for(int idx : case_list){
                data[idx] = temp[idx] % 1000000;
            }
        }
        cout << data[0] << "\n";
    }
    return 0;
}