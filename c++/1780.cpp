#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2187][2187];
int cnt[3]={0,}; //0 1 -1

void solve(int x, int y, int c){
    int cur=arr[x][y];
    bool b=false;
    if(c==1){
        if(cur==-1) cnt[2]++;
        else cnt[cur]++;
        return;
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            if(arr[x+i][y+j]!=cur){b=true;break;}
        }
        if(b) break;
    }
    if(!b){
        if(cur==-1) cnt[2]++;
        else cnt[cur]++;
        return;
    }
    solve(x,y,c/3);
    solve(x+c/3,y,c/3);
    solve(x+c*2/3,y,c/3);
    solve(x,y+c/3,c/3);
    solve(x+c/3,y+c/3,c/3);
    solve(x+c*2/3,y+c/3,c/3);
    solve(x,y+c*2/3,c/3);
    solve(x+c/3,y+c*2/3,c/3);
    solve(x+c*2/3,y+c*2/3,c/3);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> arr[i][j];
    solve(0,0,n);
    cout << cnt[2] << '\n' << cnt[0] << '\n' << cnt[1];
    return 0;
}