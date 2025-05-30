// #include <iostream>
// using namespace std;

// int main(){
// 	int n;
// 	cin >> n;
// 	int b[201][201];
// 	b[0][0]=1;
// 	n=2*n-2;
// 	for(int i=1;i<=n;i++){
// 		b[i][0]=b[i][i]=1;
// 		for(int j=1;j<i;j++) b[i][j]=(b[i-1][j-1]+b[i-1][j])%10007;
// 	}
// 	cout << b[n][n/2];
// 	return 0;
// }

// #include <iostream>
// #define MOD 10007
// using namespace std;

// int f(int a, int b){
// 	if(b==1) return a;
// 	if(b==0) return 1;
// 	int t=f(a,b/2);
// 	return ((t*t)%MOD*(b%2?a:1))%MOD;
// }

// int main(){
// 	ios_base::sync_with_stdio(false); cin.tie(NULL);
// 	int n;
// 	cin >> n;
// 	int t=1,b=1;
// 	for(int i=1;i<n;i++){
// 		t*=2*n-1-i;
// 		b*=n-i;
// 		t%=MOD;
// 		b%=MOD;
// 	}
// 	cout << (t*f(b,MOD-2))%MOD;
// 	return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dp[101][101];
int n;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	dp[1][1]=2;
	for(int i=2;i<n;i++) for(int j=1;j<=i;j++) dp[i][j]=(dp[i-1][j-1]+2*dp[i-1][j]+dp[i-1][j+1])%10007;
	int res=0;
	for(int i=1;i<n;i++) res=(res+dp[n-1][i])%10007;
	cout << res;
	return 0;
}