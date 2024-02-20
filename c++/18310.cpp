#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n); for(int i=0;i<n;i++){cin >> v[i];}
    sort(v.begin(),v.end()); if(n==1){cout << v[0]; return 0;}
    cout << v[(n-1)/2];
}