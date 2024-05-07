#include <bits/stdc++.h>
#define f first
#define s second
#define pdi pair<double, int>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ans=0;
    double m;
    while(1){
        cin >> n >> m;
        if(n==0) break;
        vector<pdi> arr(n);
        vector<vector<vector<int>>> dp(n,vector<vector<int>> ((int)m+1, vector<int> (100,0)));
        for(pdi &a:arr) cin >> a.s >> a.f;
        for(int i=0;i<=m;i++) for(double j=0.01;j<1;j+=0.01){
            int cnt=(double)(i+j)/arr[0].f;
            if(cnt>0){dp[0][i][j*100]=arr[0].s; ans=max(ans,dp[0][i][j*100]);}
        }
        for(int i=1;i<n;i++) for(int j=0;j<=m;j++) for(double k=0.00;k<1;k+=0.01){
            int cnt=(double)(j+k)/arr[0].f;
            dp[i][j][(int)k*100]=dp[i-1][j][(int)k*100];
            for(int l=1;l<=cnt;l++){
                double back=i+j-l*arr[0].f;
                string digit=to_string(100*(back-floor(back)));
                dp[i][j][k*100]=max(dp[i][j][k*100],dp[i-1][(int)back][(int)(10*(digit[0]-'0')+(digit[1]!='.')?digit[1]-'0':0)]+l*arr[i].s);
                ans=max(ans,dp[i][j][k*100]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}