#include <iostream>
using namespace std;

int n;
int arr[10000];
int m;
int cnt=0;

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int s=0;
	int e=0;
	int sum=arr[0];
	while(e<n){
		if(sum<m){
			e++;
			sum+=arr[e];
		}
		else{
			if(sum==m) cnt++;
			sum-=arr[s];
			s++;
		}
	}
	cout << cnt;
}
