#include <bits/stdc++.h>
using namespace std;

int t;

void solve(){
    int n,x,y;
    int ini;
    int ans=0;
    map<pair<int, int>, int> m;
    cin >> n >> x >> y;
    for(int i=0;i<n;i++){
        cin >> ini;
        pair<int, int> tmp={ini%x,ini%y};
        if(m.find(tmp)!=m.end()) m[tmp]++;
        else m.insert({tmp,1});
    }
    for(auto it=m.begin();it!=m.end();it++){
        auto tmp=x-it->first.first;
        auto found=find_if(m.begin(),m.end(),[tmp](pair<int, int> p)->bool{
            return p.first==tmp;
        });
        if(found!=m.end()){
            
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--) solve();
}