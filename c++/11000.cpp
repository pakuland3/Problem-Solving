#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	pair<int, int> tmp;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	priority_queue<int,vector<int>, greater<int>> e;
	for(int i=0;i<n;i++){cin >> tmp.first >> tmp.second;pq.push({tmp.first, tmp.second});}
	e.push(pq.top().second);
	pq.pop();
	int ans=1;
	while(!pq.empty()){
		if(pq.top().first>=e.top()) e.pop();
		else ans++;
		e.push(pq.top().second);
		pq.pop();
	}
	cout << ans; 	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}