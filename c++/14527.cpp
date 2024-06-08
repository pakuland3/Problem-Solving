#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto &p:a) cin >> p.first >> p.second;
    sort(a.begin(),a.end(),[](pair<int, int> l, pair<int, int> r)->bool{
        return l.second<r.second;
    });
    int ans=0,l=0,r=n-1;
    while(l<=r){
        if(a[l].first<a[r].first){
            a[r].first-=a[l].first;
            ans=max(ans,a[l].second+a[r].second);
            l++;
        }
        else if(a[l].first>a[r].first){
            a[l].first-=a[r].first;
            ans=max(ans,a[l].second+a[r].second);
            r--;
        }
        else{
            ans=max(ans,a[r].second+a[l].second);
            l++;
            r--;
        }
    }
    cout << ans;
    return 0;
}