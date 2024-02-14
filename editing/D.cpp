#include <bits/stdc++.h>
using namespace std;

int t;

void solve(){
    int n,x,y;
    int ini;
    int ans=0;
    map<pair<int, int>, pair<int, int>> m;
    cin >> n >> x >> y;
    for(int i=0;i<n;i++){
        cin >> ini;
        pair<int, int> tmp={ini%x,ini%y};
        if(m.find(tmp)!=m.end()) m[tmp].second++;
        else m.insert({{i,1},tmp});
    }
    while(!m.empty()){
        auto it=m.begin();
        pair<int, int> tmp=make_pair(x-(it->first.first),it->first.second);
        auto found=m.find(tmp);
        if(m.find(tmp)!=m.end()){
            ans+=min(it->second,found->second);
        }
        m.erase(it);
    }
    cout << ans << '\n';
}
// 1
// 9 4 10
// 14 10 2 2 11 11 13 5 6
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--) solve();
}