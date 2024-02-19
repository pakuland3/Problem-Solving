#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,l;
	int ans=0;
	cin >> n >> l;
	vector<int> arr(n);
	vector<bool> f(n);
	fill(f.begin(),f.end(),false);
	for(int i=0;i<n;i++) cin >> arr[i];
	sort(arr.begin(),arr.end());
	int s=arr[0]; int e=arr[0];
	int ck=0;
	for(int i=0;i<n;i++){
		if(!f[i]){
			while(e-s+1<=l && ck<n){e=arr[++ck];f[ck]=true;}
			if(ck==n){
				if(e-s+1>l){ans++;continue;}
			}
			f[ck]=false; s=e=arr[ck]; ans++;
		}		
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}