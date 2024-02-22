#include <bits/stdc++.h>
using namespace std;

vector<string> ans[2187];
int ck=0;

void solve(int n, bool b){
	if(n==3 && b){
		ans[ck+1].push_back("* *");
		for(int i=0;i<3;i+=2) ans[ck+i].push_back("***");
		return;
	}
	if(!b){
		string s("");
		for(int i=0;i<n;i++) s+=' ';
		for(int i=0;i<n;i++) ans[ck+i].push_back(s);
		return;
	}
    if(n!=9){
		for(int j=0;j<4;j++){
			solve(n/3,1); if(j!=2) ck-=n/3;
		}
		solve(n/3,0);
		for(int j=0;j<4;j++){
			solve(n/3,1); if(j!=0) ck-=n/3;
		}
    }
    else{
    	for(int j=0;j<3;j++) solve(3,1);
    	ck+=3;
    	solve(3,1);
    	solve(3,0);
    	solve(3,1);
    	ck+=3;
    	for(int j=0;j<3;j++) solve(3,1);
    	ck+=3;
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	solve(n,1);
	for(int i=0;i<n;i++){for(string c:ans[i]){cout << c;} cout << '\n';}
	return 0;
}