#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    vector<int> dp(n,5000);
    dp[0]=1;
    if(n>1) dp[1]=1;
    if(n>2) dp[2]=(100*(s[0]-'0')+10*(s[1]-'0')+s[2]-'0'<=641)?1:2;
    for(int i=3;i<n;i++){
        for(int j=0;j<2;j++) if(s[i-j]!='0') dp[i]=min(dp[i],dp[i-j-1]+1);
        if(s[i-2]!='0' && 100*(s[i-2]-'0')+10*(s[i-1]-'0')+s[i]-'0'<=641) dp[i]=min(dp[i],dp[i-3]+1); 
    }
    cout << dp[n-1];
    return 0;
}