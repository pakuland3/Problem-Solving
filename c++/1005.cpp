#include <bits/stdc++.h>
using namespace std;

int t;

void solve(){
    int n,k;
    vector<int> v[1001]; //next vector
    vector<int> h[1001]; //req vector
    int reqarr[1001];
    memset(reqarr,0,sizeof(reqarr));
    int dp[1001];
    int arr[1001];
    int tmp[2];
    int target;
    queue<int> q;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=0;i<k;i++){
        cin >> tmp[0] >> tmp[1];
        v[tmp[0]].push_back(tmp[1]);
        h[tmp[1]].push_back(tmp[0]);
        reqarr[tmp[1]]++;
    }
    cin >> target;
    for(int i=1;i<=n;i++){if(reqarr[i]==0) q.push(i);}
    while(!q.empty()){
        int x=q.front();
        q.pop();
        dp[x]=arr[x];
        int maxi=0;
        for(int i=0;i<h[x].size();i++) maxi=max(maxi,dp[h[x][i]]);
        dp[x]+=maxi;
        for(int i=0;i<v[x].size();i++){
            reqarr[v[x][i]]--;
            if(reqarr[v[x][i]]==0) q.push(v[x][i]);
        }
    }
    cout << dp[target] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--) solve();
}