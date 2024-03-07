#include <bits/stdc++.h>
using namespace std;

int n;
int ans[2]={0,};
bool f[128][128];

void solve(int x, int y, int c){
    bool stc=f[x][y];
    if(c==1){ans[stc]++;return;}
    bool b=false;
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            if(f[x+i][y+j]!=stc){b=true;break;}
        }
        if(b) break;
    }
    if(!b) ans[stc]++;
    else{
        solve(x,y,c/2);
        solve(x,y+c/2,c/2);
        solve(x+c/2,y,c/2);
        solve(x+c/2,y+c/2,c/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> f[i][j];
    solve(0,0,n);
    cout << ans[0] << '\n' << ans[1];
    return 0;
}