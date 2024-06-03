#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int n=s.length();
    vector<pair<string, int>> a(s.length());
    for(int i=0;i<n;i++){
        a[i].second=i;
        a[i].first=s;
        s.erase(s.begin());
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) cout << a[i].second << '\n';
    return 0;
}