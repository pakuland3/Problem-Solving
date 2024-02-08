#include <bits/stdc++.h>
using namespace std;

int t;

void solve(){
    int n,k;
    vector<int> v[1001];
    vector<int> h[1001];
    vector<int> starts;
    int dp[1001];
    int arr[1001];
    int tmp[2];
    int target;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=0;i<k;i++){
        cin >> tmp[0] >> tmp[1];
        v[tmp[1]].push_back(tmp[0]);
        h[tmp[0]].push_back(tmp[1]);
    }
    cin >> target;
    for(int i=1;i<=n;i++){
        if(v[i].size()==0){
            starts.push_back(i);
        }
    }
    queue<int> q;
    bool vis[1001];
    for(auto elem:starts){
        q.push(elem);
        vis[elem]=true;
    }
    while(!q.empty()){
        int x=q.front();
        if(!vis[x]) vis[x]=true;
        q.pop();
        dp[x]=arr[x];
        int maxi=0;
        for(int i=0;i<v[x].size();i++) maxi=max(maxi,dp[v[x][i]]);
        dp[x]+=maxi;
        for(int i=0;i<h[x].size();i++){
            if(!vis[h[x][i]]) q.push(h[x][i]);
        }
    }
    cout << dp[target] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--) solve();
}