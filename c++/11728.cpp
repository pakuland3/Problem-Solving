#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n+m);
    for(int &i:a) cin >> i;
    sort(a.begin(),a.end());
    for(int &i:a) cout << i << ' ';
    return 0;
}