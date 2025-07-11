#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[200001][5];
int pfx[200001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> pfx[i];
        pfx[i]^=pfx[i-1];
        for(int j=1;j<5;j++){
            int b=i-j;
            if(b<0) break;
            if(!b){
                dp[i][j]=pfx[i];
                break;
            }
            int c=min(b,4);
            for(int k=1;k<=c;k++){
                if(k==j) continue;
                dp[i][j]=max(dp[i][j],dp[b][k]+(pfx[i]^pfx[b]));
            }
        }
    }
    ll mx=0;
    for(int i=1;i<=min(n,4);i++) mx=max(mx,dp[n][i]);
    cout << mx;
    return 0;
}