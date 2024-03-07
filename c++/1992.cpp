#include <bits/stdc++.h>
using namespace std;

string s;
int n;
bool f[64][64];

void solve(int x, int y, int c){
    bool cur=f[x][y];
    bool b=false;
    if(c==1){cout << cur;return;}
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            if(f[x+i][y+j]!=cur){b=true;break;}
        }
        if(b) break;
    }
    if(!b){cout << cur;return;}
    cout << '(';
    solve(x,y,c/2);
    solve(x,y+c/2,c/2);
    solve(x+c/2,y,c/2);
    solve(x+c/2,y+c/2,c/2);
    cout << ')';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++) f[i][j]=s[j]-'0';
    }
    solve(0,0,n);
    return 0;
}