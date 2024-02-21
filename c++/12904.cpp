#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s,t; cin >> s >> t; int sl=s.length(); int tl=t.length();
	bool st=true;
	while(tl>0 && tl!=sl){
		if(st){
			if(t[tl-1]=='B') st=false;
			t.erase(tl-1,1);
		}
		else{
			if(t[0]=='B') st=true;
			t.erase(0,1);
		}
		tl--;		
	}
	if(tl==0){cout << 0; return 0;}
	if(st) for(int i=0;i<tl;i++){if(t[i]!=s[i]){cout << 0; return 0;}}
	else for(int i=0;i<tl;i++){if(t[i]!=s[sl-(i+1)]){cout << 0; return 0;}}
	cout << 1;
}