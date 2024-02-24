#include <bits/stdc++.h>
#define INF 10000000000
typedef long long ll;
using namespace std;

void solve(){
	int n,d,c; cin >> n >> d >> c;
	int cnt=1;
	ll ans=0;
	vector<pair<int, int>> graph[10001];
	ll dp[10001]; fill(dp,dp+n+1,INF);
	for(int i=0;i<d;i++){
		int a,b,s; cin >> a >> b >> s;
		graph[b].push_back({a,s});
	}
	priority_queue<pair<ll, int>,vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dp[c]=0;
	pq.push({0,c});
	while(!pq.empty()){
		int now=pq.top().second;
		ll dist=pq.top().first;
		pq.pop();
		if(dp[now]<dist) continue;
		for(int i=0;i<(int)graph[now].size();i++){
			ll cost=dist+graph[now][i].second;
			if(dp[graph[now][i].first]>cost){
				if(dp[graph[now][i].first]==INF) cnt++;
				dp[graph[now][i].first]=cost;
				pq.push({cost,graph[now][i].first});
			}
		}
	}
	for(int i=1;i<=n;i++) if(dp[i]!=INF){ans=max(ans,dp[i]);}
	cout << cnt << ' ' << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}