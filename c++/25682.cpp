#include <bits/stdc++.h>
using namespace std;

int m,n,k,pm[2000][2000][2]={0,},ans=4e6+1;
char board[2000][2000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin >> board[i][j];
    if(board[0][0]=='W') pm[0][0][0]=1;
    else pm[0][0][1]=1;
    for(int i=1;i<m;i++){
        pm[i][0][0]=pm[i-1][0][0];
        pm[i][0][1]=pm[i-1][0][1];
        if(i%2==0){
            if(board[i][0]=='W') pm[i][0][0]++;
            else pm[i][0][1]++;
        }
        else{
            if(board[i][0]=='W') pm[i][0][1]++;
            else pm[i][0][0]++;
        }
    }
    for(int i=1;i<n;i++){
        pm[0][i][0]=pm[0][i-1][0];
        pm[0][i][1]=pm[0][i-1][1];
        if(i%2==0){
            if(board[0][i]=='W') pm[0][i][0]++;
            else pm[0][i][1]++;
        }
        else{
            if(board[0][i]=='W') pm[0][i][1]++;
            else pm[0][i][0]++;
        }
    }
    for(int i=1;i<m;i++) for(int j=1;j<n;j++){
        pm[i][j][0]=pm[i-1][j][0]+pm[i][j-1][0]-pm[i-1][j-1][0];
        pm[i][j][1]=pm[i-1][j][1]+pm[i][j-1][1]-pm[i-1][j-1][1];
        if((i+j)%2==0){
            if(board[i][j]=='W') pm[i][j][0]++;
            else pm[i][j][1]++;
        }
        else{
            if(board[i][j]=='W') pm[i][j][1]++;
            else pm[i][j][0]++;
        }
    }
    for(int i=k-1;i<m;i++) for(int j=k-1;j<n;j++){
        int ld[2]={i,j-k}, rw[2]={i-k,j}, o[2]={i-k,j-k};
        int corValue[2]={0,0};
        if(j>=k && i>=k) for(int l=0;l<2;l++) corValue[l]-=pm[o[0]][o[1]][l];
        if(i>=k) for(int l=0;l<2;l++) corValue[l]+=pm[rw[0]][rw[1]][l];
        if(j>=k) for(int l=0;l<2;l++) corValue[l]+=pm[ld[0]][ld[1]][l];
        ans=min(ans,min(pm[i][j][1]-corValue[1],pm[i][j][0]-corValue[0]));
    }
    cout << ans;
    return 0;
}