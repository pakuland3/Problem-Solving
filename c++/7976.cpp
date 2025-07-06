#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,k;
int cnt[1000001][2];
int dp[1000001][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        cnt[i%k][t&1]++;
    }
    for(int i=0;i<k;i++){
        if(i!=0){
            dp[i][0]=min(dp[i-1][0]+cnt[i][1],dp[i-1][1]+cnt[i][0]);
            dp[i][1]=min(dp[i-1][0]+cnt[i][0],dp[i-1][1]+cnt[i][1]);
        }
        else dp[i][0]=cnt[i][1],dp[i][1]=cnt[i][0];
    }
    cout << dp[k-1][0];
    return 0;
}