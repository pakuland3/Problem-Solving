#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    int dx[]={-2,-3};
    cin >> t;
    for(int tt=0;tt<t;tt++){
        int n;
        cin >> n;
        vector<int> a(n,0),dp(n,0);
        for(int &s:a) cin >> s;
        for(int i=0;i<n;i++){
            if(i!=0) dp[i]=dp[i-1];
            for(int j=0;j<2;j++){
                int nx=i+dx[j];
                if(nx<0) dp[i]=max(dp[i],a[i]);
                else dp[i]=max(dp[i],dp[nx]+a[i]);
            }
        }
        cout << "Data Set " << tt+1 << ":\n" << dp[n-1] << "\n\n";
    }
    return 0;
}