#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,l;
ll t=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    vector<pair<ll, pair<ll, ll>>> tl(n+1);
    for(int i=0;i<n;i++) cin >> tl[i].first >> tl[i].second.first >> tl[i].second.second; tl[n]={0,{0,0}};
    sort(tl.begin(),tl.end(),[](pair<ll, pair<ll, ll>> l, pair<ll, pair<ll, ll>> r)->bool{
        return l.first<r.first;
    });
    for(int i=1;i<=n;i++){
        t+=tl[i].first-tl[i-1].first;
        if(t<tl[i].second.first) continue;
        if(tl[i].second.first+tl[i].second.second<t){
            ll tmp=t-t%(tl[i].second.first+tl[i].second.second);
            if(tmp+tl[i].second.first<=t) t=tmp+tl[i].second.first+tl[i].second.second;
        }
        else t=tl[i].second.first+tl[i].second.second;
    }
    cout << t+l-tl[n].first;
    return 0;
}