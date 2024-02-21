#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int ans=0;
	int ten[8]; for(int i=0;i<8;i++) ten[i]=pow(10,i); 
	int arr[26]; memset(arr,0,sizeof(arr));
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		string s; cin >> s;
		for(int i=0;i<(int)s.length();i++) arr[s[i]-'A']+=ten[s.length()-(i+1)];
	}
	for(int i=0;i<26;i++) if(arr[i]>0){pq.push(arr[i]);}
	int c=9;
    while(!pq.empty()){
		ans+=c*pq.top(); c--; pq.pop();   	
    }
    cout << ans;    
}