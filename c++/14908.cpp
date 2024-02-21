#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int s,t;
	int n; cin >> n; vector<pair<double, int>> arr(n);
	for(int i=0;i<n;i++){cin >> t >> s;arr[i].first=(double)t/s;arr[i].second=i+1;}
	sort(arr.begin(),arr.end(),[](pair<double, int> l, pair<double, int> r)->bool{
		if(l.first==r.first) return l.second<r.second;
		else return l.first<r.first;
	});
	for(int i=0;i<n;i++) cout << arr[i].second << ' ';
	return 0;
}