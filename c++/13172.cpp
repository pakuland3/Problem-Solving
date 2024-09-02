#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007ll
using namespace std;

ll p(ll a, ll b){
	if(b==0) return 1;
	if(b==1) return a;
	ll c=p(a,b/2)%MOD; c*=c; c%=MOD;
	if(b%2) return (a*c)%MOD;
	return c;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m;
	cin >> m;
	ll res=0;
	while(m--){
		ll a,b;
		cin >> a >> b;
		res+=(b*p(a,MOD-2ll))%MOD;
		res%=MOD;
	}
	cout << res;
}