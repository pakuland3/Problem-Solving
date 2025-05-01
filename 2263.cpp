#include <bits/stdc++.h>
using namespace std;

int in[100001],po[100001],idx[100001];

void solve(int l, int r, int a, int b){
	if(r<l) return;
	cout << po[b] << ' ';
	if(l==r) return;
	int j=idx[po[b]];
	solve(l,j-1,a,a+j-1-l);
	solve(j+1,r,a+j-l,b-1);
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> in[i];
		idx[in[i]]=i;
	}
	for(int i=0;i<n;i++) cin >> po[i];
	solve(0,n-1,0,n-1);
    return 0;
}