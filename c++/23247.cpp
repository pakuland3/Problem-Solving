#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int pfx[301][301];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n;
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> pfx[i][j];
            pfx[i][j]+=pfx[i-1][j]+pfx[i][j-1]-pfx[i-1][j-1];
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n && j<i+10;j++){
            for(int k=1;k<=m;k++){
                for(int l=k;l<=m && (j-i+1)*(l-k+1)<=10;l++){
                    if(pfx[l][j]-pfx[l][i-1]-pfx[k-1][j]+pfx[k-1][i-1]==10) res++;
                }
            }
        }
    }
    cout << res;
    return 0;
}