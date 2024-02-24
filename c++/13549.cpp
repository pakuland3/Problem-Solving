#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,k; cin >> n >> k;
	int d[100]; memset(d,-1,sizeof(d));
	if(k<=n){cout << n-k; return 0;}
	queue<int> q; q.push(n); d[n]=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int nx:{x-1,x+1}){
			if(100000<nx || nx<0) continue;
			if(d[nx]!=-1 && d[nx]>d[x]+1){
				d[nx]=d[x]+1; q.push(nx);		
			}
			else if(d[nx]==-1){d[nx]=d[x]+1;q.push(nx);}
		}
		int nx=2*x;
		if(100000<nx || nx<0) continue;
		if(d[nx]!=-1 && d[nx]>d[x]){
			d[nx]=d[x]; q.push(nx);
		}
		else if(d[nx]==-1){d[nx]=d[x];q.push(nx);}
	}
	cout << d[k];
}