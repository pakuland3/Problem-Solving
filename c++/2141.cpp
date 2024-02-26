#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,X,A; cin >> n;
	vector<pair<int, int>> v;
	vector<pair<ll, ll>> d;
	for(int i=0;i<n;i++){cin >> X >> A; v.push_back({X,A});}
	sort(v.begin(),v.end(),[](pair<int, int> l, pair<int, int> r)->bool{return l.first<r.first;});
	d.push_back({0,0});
	for(int i=1;i<n;i++) d.push_back({d[i-1].first+v[i-1].second,0});
	for(int i=1;i<n;i++) d[n-(i+1)].second=d[n-i].second+v[n-i].second;
	int l=0;
	int r=n-1;
	while(d[l].second>d[l].first) l++;
	while(d[r].first>d[r].second) r--;
	ll dl=d[l].first-d[l].second;
	ll dr=d[r].second-d[r].first;
	if(dl<dr) cout << v[l].first;
	else cout << v[r].first;
	return 0;
}