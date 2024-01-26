#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000000];
bool flag=false;
int ans;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n,[](int l, int r)->bool{return l>r;});
	for(int i=0;i<n-2;i++){
		if(arr[i]<arr[i+1]+arr[i+2]){
			ans=arr[i]+arr[i+1]+arr[i+2];
			break;
		}
	}
	if(ans!=0) cout << ans;
	else cout << -1;
}