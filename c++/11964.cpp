#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t,a,b;
    cin >> t >> a >> b;
    auto rn=[&t](vector<int> &a, int b){
        for(int i=b;i<=t;i++){
            int c=i/b;
            for(int j=1;!a[i] && j<=c;j++) if(a[i-j*b]) a[i]=1;
        }
    };
    auto solve=[&t,&rn](int a, int b) -> int {
        vector<int> dp(t+1,0);
        dp[0]=1;
        for(int i=1;i*a<=t;i++){
            dp[a*i]=1;
            dp[a*i/2]=1;
        }
        rn(dp,a);
        rn(dp,b);
        for(int i=t;i>0;i--) if(dp[i]) return i;
    };
    int ans=max(solve(a,b),solve(b,a));
    vector<int> dp(t+1,0);
    dp[0]=1;
    rn(dp,a);
    rn(dp,b);
    for(int i=1;i<=t;i++) if(dp[i]) dp[i/2]=1;
    rn(dp,a);
    rn(dp,b);
    for(int i=t;i>0;i--){
        if(dp[i]){
            ans=max(ans,i);
            break;
        }
    }
    cout << ans;
    return 0;
}