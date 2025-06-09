#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin >> n;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    cin >> k;
    vector<pair<int,int>> dp(50001,{0,0});
    dp[0]={1,0};
    for(int i=0;i<n;i++){
        for(int j=50000;j>0;j--){
            int c=min(k,j/a[i]);
            while(c){
                if(dp[j-c*a[i]].first && dp[j-c*a[i]].second+c<=k){
                    if(dp[j].first) dp[j].second=min(dp[j].second,dp[j-c*a[i]].second+c);
                    else dp[j]={1,dp[j-c*a[i]].second+c};
                }
                c--;
            }
        }
    }
    for(int i=1;i<=50000;i++){
        if(!dp[i].first){
            cout << (i&1?"jjaksoon":"holsoon") << " win at " << i;
            return 0; 
        }
    }
    return 0;
}