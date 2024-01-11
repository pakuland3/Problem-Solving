#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int coin[101];
int n;
int k;

int main(){
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
	
	dp[0]=1;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> coin[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=coin[i];j<=k;j++){
			dp[j]+=dp[j-coin[i]];
		}
	}
	
	cout << dp[k];
}
