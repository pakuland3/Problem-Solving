#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int d,m;
    cin >> d >> m;
    vector<vector<ll>> dp(d+1,vector<ll> (d/2+1,0));
    dp[0][0]=1;
    for(int i=1;i<=d;i++){
        for(int j=0;j<=d/2;j++){
            if(i!=d && j==0) continue;
            for(int nj:{j-1,j+1}){
                if(nj<0 || nj>d/2) continue;
                dp[i][j]=(dp[i][j]+dp[i-1][nj])%m;
            }
        }
    }
    cout << dp[d][0];
    return 0;
}