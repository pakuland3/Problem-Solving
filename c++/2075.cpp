#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n*n);
    for(int i=0;i<n*n;i++) cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());
    cout << a[n-1];
    return 0;
}