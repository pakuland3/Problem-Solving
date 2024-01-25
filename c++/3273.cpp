#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100001];
int x;
int cnt=0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	cin >> x;
	sort(arr,arr+n);
	if(n!=1){
		int s=0;
		int e=n-1;
		while(s<e){
			if(arr[s]+arr[e]>=x){
				if(arr[s]+arr[e]==x){
					s++;
					cnt++;
				}
				e--;
			}
			else{
				s++;
			}
		}
	}
	cout << cnt;
}
