#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string kpos, spos;
    int n;
    cin >> kpos >> spos >> n;
    int kposx, kposy, sposx, sposy;
    kposx = kpos[0] - 'A' + 1;
    kposy = kpos[1] - '1' + 1;
    sposx = spos[0] - 'A' + 1;
    sposy = spos[1] - '1' + 1;

    while(n--){
        string cmd;
        cin >> cmd;

        int nkposx, nkposy, nsposx, nsposy;
        nkposx = kposx; nkposy = kposy;
        nsposx = sposx; nsposy = sposy;

        if(cmd == "R"){nkposx ++;}
        else if(cmd == "L"){nkposx --;}
        else if(cmd == "T"){nkposy ++;}
        else if(cmd == "B"){nkposy --;}
        else if(cmd == "RT"){nkposx ++; nkposy ++;}
        else if(cmd == "RB"){nkposx ++; nkposy --;}
        else if(cmd == "LT"){nkposx --; nkposy ++;}
        else if(cmd == "LB"){nkposx --; nkposy --;}

        if(nkposx == nsposx && nkposy == nsposy){
            nsposx += nkposx - kposx;
            nsposy += nkposy - kposy;
        }
        if(nkposx >= 1 && nkposx <= 8 && nkposy >= 1 && nkposy <= 8 && nsposx >= 1 && nsposx <= 8 && nsposy >= 1 && nsposy <= 8){
            kposx = nkposx; kposy = nkposy; sposx = nsposx; sposy = nsposy;
        }
    }
    cout << (char)(kposx + 'A' - 1) << (char)(kposy + '1' - 1) << "\n";
    cout << (char)(sposx + 'A' - 1) << (char)(sposy + '1' - 1) << "\n";
}