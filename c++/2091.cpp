#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("in","r",stdin);
    // int t;
    // cin >> t;
    // while(t--){
        int x;
        cin >> x;
        vector<int> c(4);
        for(int &t:c) cin >> t;
        vector<int> m={1,5,10,25};
        vector<vector<vector<int>>> cnt(2,vector<vector<int>> (x+1,vector<int> (4,0)));
        vector<vector<int>> dp(2,vector<int> (x+1,-1)); dp[0][0]=0; dp[1][0]=0;
        for(int i=0;i<4;i++) for(int j=1;j<=x;j++){
            dp[i%2][j]=dp[!(i%2)][j];
            for(int k=0;k<4;k++) cnt[i%2][j][k]=cnt[!(i%2)][j][k];
            int counts=min(j/m[i],c[i]);
            for(int l=1;l<=counts;l++){
                if(j>=l*m[i] && dp[!(i%2)][j-l*m[i]]!=-1){
                    if(dp[!(i%2)][j-l*m[i]]-cnt[!(i%2)][j-l*m[i]][i]+l>dp[i%2][j]){
                        dp[i%2][j]=l;
                        cnt[i%2][j][i]=l;
                        for(int k=0;k<4;k++) if(k!=i){cnt[i%2][j][k]=cnt[!(i%2)][j-l*m[i]][k]; dp[i%2][j]+=cnt[i%2][j][k];}
                    }
                }
            }
        }
        for(int i=0;i<4;i++) cout << cnt[1][x][i] << ' ';
    //     cout << '\n';
    // }
    return 0;
}