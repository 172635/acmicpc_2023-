#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int s = 1;;s++){
        int o, w;
        cin >> o >> w;
        if(o == 0){
            break;
        }
        char com;
        int num;
        while(true){
            cin >> com >> num;
            if(com == '#'){
                cout << s << ' ';
                if(w > 0){
                    cout << ((w > o/2 && w < 2*o)?":-)\n":":-(\n");
                }else{
                    cout << "RIP\n";
                }
                break;
            }else if(w > 0){
                if(com == 'E'){
                    w -= num;
                }else{
                    w += num;
                }
            }
        }
    }
    return 0;
}