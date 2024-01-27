#include <bits/stdc++.h>
using namespace std;

string S;
int n,m,cnt=0,ans=0;
bool ioturn=false; //true i turn
                   //false o turn
int main(){
	cin >> n >> m >> S;
	for(int i=1;i<=m;i++){
		if(ioturn){
			if(S[i-1]=='O'){
				ioturn=false;
				cnt++;
			}
			else cnt=1;
		}
		else{
			if(S[i-1]=='I'){
				ioturn=true;
				cnt++;
			}
			else{
				cnt=0;
			}
		}
		if(cnt==2*n+1){
			ans++;
			cnt=2*n-1;
		}
	}
	cout << ans;
}