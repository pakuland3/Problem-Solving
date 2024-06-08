#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

char a[8][8];
int ans=0;
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};

int count(int i, int j){
    int cnt=0;
    for(int k=0;k<8;k++){
        int tmp=0;
        for(int l=1;l<8;l++){
            int nr=i+dx[k]*l;
            int nc=j+dy[k]*l;
            if(7<nr || nr<0 || 7<nc || nc<0) break;
            if(a[nr][nc]=='.') break;
            if(a[nr][nc]=='B'){
                if(l!=1) cnt+=tmp;
                break;
            }
            tmp++;
        }
    }
    return cnt;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) cin >> a[i][j];
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) if(a[i][j]=='.') ans=max(ans,count(i,j));
    cout << ans;
    return 0;
}