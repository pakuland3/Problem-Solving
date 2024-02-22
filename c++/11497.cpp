#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n; vector<int> arr(n); for(int i=0;i<n;i++) cin >> arr[i];
	sort(arr.begin(),arr.end()); int ans=max(arr[1]-arr[0],arr[n-1]-arr[n-2]);
	for(int i=2;i<n;i++) ans=max(ans,arr[i]-arr[i-2]);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while(t--) solve();
	return 0;
}