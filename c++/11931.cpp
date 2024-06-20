#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &s:a) cin >> s;
    sort(a.begin(),a.end(),greater<int>());
    for(int &s:a) cout << s << '\n';
    return 0;
}