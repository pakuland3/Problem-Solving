#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int ans=1;
    int dp[500]; fill(dp,dp+n,1);
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(),v.end(),[](pair<int, int> l, pair<int, int> r)->bool{return l.first<r.first;});
    for(int i=1;i<n;i++) for(int j=0;j<i;j++){
        if(v[i].second>v[j].second) dp[v[i].second]=max(dp[v[i].second],dp[v[j].second]+1);        
        ans=max(ans,dp[v[i].second]);
    }
    cout << n-ans;
    return 0;
}