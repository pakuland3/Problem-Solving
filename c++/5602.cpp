#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,m;
int cnt[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        bool a;
        cin >> a;
        if(a) cnt[j]++;
    }
    vector<pair<int,int>> a;
    for(int i=0;i<m;i++) a.push_back({cnt[i],i});
    sort(a.begin(),a.end(),[](pair<int,int> &l, pair<int,int> r) -> bool {if(l.first==r.first) return l.second<r.second; return l.first>r.first; });
    for(int i=0;i<a.size();i++) cout << a[i].second+1 << ' ';
    return 0;
}