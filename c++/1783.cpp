#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	if(m>=5){
		if(n==1) cout << 1;
		else if(n==2){
			if(m<=2) cout << 1;
			else if(m<=4) cout << 2;
			else if(m<=6) cout << 3;
			else cout << 4;
		}
		else if(m<=6) cout << 4;
		else cout << m-2;
	}
	else{
		if(n==1) cout << 1;
		else if(n==2){
			if(m==3 || m==4) cout << 2;
			else cout << 1;
		} 
		else cout << m;
	}
}

int main(){
	solve();
}