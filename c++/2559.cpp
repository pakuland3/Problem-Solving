#include <iostream>
using namespace std;

int n,k;
int arr[100000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int sum=0;
	for(int i=0;i<k;i++){
		sum+=arr[i];
	}
	int maxi=sum;
	for(int i=k;i<n;i++){
		sum-=arr[i-k];
		sum+=arr[i];
		maxi=max(maxi,sum);
	}
	cout << maxi;
}
