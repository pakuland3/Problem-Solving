#include <bits/stdc++.h>
#define INF 200000000001
#define F first
#define S second
#define pli pair<ll,int>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	int dx[]={1,-1};
	cin >> n;
	vector<ll> a(n+1),b(n+1),d(n+2,INF);
	vector<vector<pli>> graph(n+2);
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		cin >> b[i];
		for(int j=0;j<2;j++){
			int nx=i+dx[j]*a[i];
			if(n<nx || nx<1) graph[n+1].push_back({b[i],i});
			else graph[nx].push_back({b[i],i});
		}
	}
	priority_queue<pli,vector<pli>,greater<pli>> pq;
	d[n+1]=0;
	pq.push({0,n+1});
	while(!pq.empty()){
		int cur=pq.top().S;
		ll dis=pq.top().F;
		pq.pop();
		for(int i=0;i<graph[cur].size();i++){
			int next=graph[cur][i].S;
			ll cost=dis+graph[cur][i].F;
			if(cost<d[next]){
				d[next]=cost;
				pq.push({cost,next});
			}
		}
	}
	for(int i=1;i<=n;i++) cout << d[i] << ' ';
	return 0;
}