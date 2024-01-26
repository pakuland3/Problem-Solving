#include <iostream>
using namespace std;

int n;
int s;
int arr[20];
int cnt=0;

void solve(int l, int sum, int ni){
	if(sum==s && l!=0) cnt++;
	if(l==n) return;
	
	for(int i=ni;i<n;i++){
		solve(l+1,sum+arr[i],i+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	solve(0,0,0);
	cout << cnt;
}