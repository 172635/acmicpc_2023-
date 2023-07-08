#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int num[8];
    for(int i=0;i<n;i++){
        scanf("%d", &num[i]);
    }
    int temp;
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(num[j] > num[j+1]){
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    int a[8];
    for(int i=0;i<m;i++){
        a[i] = i + 1;
    }
    while(1){
        for(int i=0;i<m;i++){
            if(i != m-1){
                printf("%d ", num[a[i]-1]);
            }else{
                printf("%d\n", num[a[i]-1]);
            }
        }
        for(int check = 0; check == 0;){
            a[m - 1]++;
            check = 1;
            for(int i=0;i<m-1;i++){
                if(a[m - 1] == a[i]){
                    check = 0;
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            if(a[i] == n+1){
                for(int check=0;check==0;){
                    a[i-1]++;
                    check = 1;
                    for(int j=0;j<i-1;j++){
                        if(a[i-1] == a[j]){
                            check = 0;
                        }
                    }
                }
            }else{
                int rest[8];
                int rp = 0;
                for(int j=1;j<=n;j++){
                    for(int k=0;k<=i;k++){
                        if(a[k] == j){
                            break;
                        }
                        if(k == i){
                            rest[rp] = j;
                            rp ++;
                        }
                    }
                }
                for(int j=i+1;j<m;j++){
                    a[j] = rest[j-i-1];
                }
                break;
            }
        }
        if(a[0] == n+1){
            break;
        }
    }
    return 0;
}