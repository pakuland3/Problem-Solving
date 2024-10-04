#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    vector<int> b(a);
    sort(b.begin(),b.end());
    auto it=unique(b.begin(),b.end());
    for(int i=0;i<n;i++) cout << lower_bound(b.begin(),it,a[i])-b.begin() << ' ';
    return 0;
}