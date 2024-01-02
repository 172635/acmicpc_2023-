#include <bits/stdc++.h>

using namespace std;

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _n;
    cin >> _n;
    string st;
    cin >> st;
    if(st.length() % 2 == 0){
        printf("junhui\n");
    }else{
        int check = 0;
        //left
        int left = 0;
        int right = 0;
        int n = st.length() / 2;
        int il = n-1;
        int ir = n;
        while(il >= 0){
            if(st[il] == '('){
                if(left == 0){
                    right += 1;
                }else{
                    left -= 1;
                }
            }else{
                left += 1;
            }
            if(st[ir] == '('){
                right += 1;
            }else{
                if(right == 0){
                    left += 1;
                }else{
                    right -= 1;
                }
            }
            if(left == 0 && right == 0){
                check = 1;
                break;
            }
            il --;
            ir ++;
        }

        //right
        left = 0;
        right = 0;
        il = n;
        ir = n+1;
        while(il >= 0){
            if(st[il] == '('){
                if(left == 0){
                    right += 1;
                }else{
                    left -= 1;
                }
            }else{
                left += 1;
            }
            if(st[ir] == '('){
                right += 1;
            }else{
                if(right == 0){
                    left += 1;
                }else{
                    right -= 1;
                }
            }
            if(left == 0 && right == 0){
                check = 1;
                break;
            }
            il --;
            ir ++;
        }

        if(check == 0){
            printf("junhui\n");
        }else{
            printf("jimin\n");
        }
    }
    return 0;
}