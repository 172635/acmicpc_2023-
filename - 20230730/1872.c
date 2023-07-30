#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    char ch = getchar();
    for(int t_ = 0; t_ < t; t_ ++){
        char str[10001];
        int index;
        for(index=0;index<10001;index++){
            ch = getchar();
            if(ch == '\n'){
                break;
            }
            str[index] = ch;
        }
        int lastM = 0;
        int Mnum = 0;
        for(int i=lastM;i<index;i++){
            if(str[i] == 'm'){
                lastM = i;
                Mnum ++;
            }
        }
        int lastD = lastM;
        int Dnum = 0;
        for(int i=lastD;i<index;i++){
            if(str[i] == 'd'){
                lastD = i;
                Dnum = 1;
                break;
            }
        }
        int lastC = lastD;
        int Cnum = 0;
        for(int i=lastC;i<index; i++){
            if(str[i] == 'c'){
                lastC = i;
                Cnum ++;
                if(Cnum == 3){
                    break;
                }
            }
        }
        int firstX = lastC;
        int Xcheck = 0;
        for(int i=firstX;i<index; i++){
            if(str[i] == 'x'){
                firstX = i;
                Xcheck = 1;
                break;
            }
        }
        int C4 = firstX;
        int XCcheck = 0;
        for(int i=C4;i<index;i++){
            if(str[i] == 'c'){
                C4 = i;
                XCcheck = 1;
                break;
            }
        }
        int lastL;
        int lastX;
        int Lnum = 0;
        int Xnum = 0;
        if(Xcheck == 1 && XCcheck == 1){
            Xnum = 9;
            lastX = C4;
        }else{
            lastL = lastC;
            for(int i=lastL;i<index; i++){
                if(str[i] == 'l'){
                    lastL = i;
                    Lnum = 1;
                    break;
                }
            }
            lastX = lastL;
            for(int i=lastX;i<index; i++){
                if(str[i] == 'x'){
                    lastX = i;
                    Xnum ++;
                    if(Xnum == 3){
                        break;
                    }
                }
            }
        }
        int firstI = lastX;
        int Icheck = 0;
        for(int i=firstI;i<index; i++){
            if(str[i] == 'i'){
                firstI = i;
                Icheck = 1;
                break;
            }
        }
        int X4 = firstI;
        int IXcheck = 0;
        for(int i=X4;i<index;i++){
            if(str[i] == 'x'){
                X4 = i;
                IXcheck = 1;
                break;
            }
        }
        int lastV;
        int lastI;
        int Vnum = 0;
        int Inum = 0;
        if(Icheck == 1 && IXcheck == 1){
            Inum = 9;
            lastI = X4;
        }else{
            lastV = lastX;
            for(int i=lastV;i<index; i++){
                if(str[i] == 'v'){
                    lastV = i;
                    Vnum = 1;
                    break;
                }
            }
            lastI = lastV;
            for(int i=lastI;i<index; i++){
                if(str[i] == 'i'){
                    lastI = i;
                    Inum ++;
                    if(Inum == 3){
                        break;
                    }
                }
            }
        }
        printf("%lld\n", Mnum*(long long int)1000+Dnum*500+Cnum*100+Lnum*50+Xnum*10+Vnum*5+Inum);
    }
}