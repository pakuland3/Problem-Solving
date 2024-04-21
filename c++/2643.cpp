#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ans=1;
    cin >> n;
    vector<pair<int, int>> arr(n);
    vector<int> dp(n,1);
    for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(),arr.end(),[](pair<int, int> l, pair<int, int > r)->bool{
        if(l.first*l.second!=r.first*r.second) return l.first*l.second>r.first*r.second;
        if(l.first==r.first) return l.second>r.second;
        else return l.first>r.first;
    });
    for(int i=1;i<n;i++) for(int j=0;j<i;j++){
        if(arr[i].first<=arr[j].first && arr[i].second<=arr[j].second) dp[i]=max(dp[i],dp[j]+1);
        if(arr[i].first<=arr[j].second && arr[i].second<=arr[j].first) dp[i]=max(dp[i],dp[j]+1);
        ans=max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}