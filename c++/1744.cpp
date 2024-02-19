#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){
	int n;
	ll ans=0;
	cin >> n;
	int tmp;
	priority_queue<int> ppq;
	priority_queue<int> npq;
	bool zero=false;
	for(int i=0;i<n;i++){cin >> tmp;
		if(tmp>0) ppq.push(tmp);
		else if(tmp==0) zero=true;
		else npq.push(-tmp);	
	}
	while(!ppq.empty()){
		if(ppq.size()==1){ans+=ppq.top();ppq.pop();continue;}
		if(ppq.top()==1){ans+=1;ppq.pop();continue;}
		int a=ppq.top(); ppq.pop();
		if(ppq.top()==1){ans+=a+1;ppq.pop();continue;}
		a*=ppq.top(); ppq.pop();
		ans+=a;
	}
	while(!npq.empty()){
		if(npq.size()==1){
			if(zero) break;
			ans-=npq.top(); npq.pop();
			continue;
		}
		int a=npq.top(); npq.pop(); a*=npq.top(); npq.pop();
		ans+=a;        		
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}