#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("../tmp/tmp-folder/xor6.in","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    bool a;
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        cin >> a;
        if(a) ans.push_back({i,j});
    }
    cout << ans.size() << '\n';
    for(auto &p:ans) cout << p.second << ' ' << p.second << ' ' << p.first << ' ' << p.first << '\n';
    return 0;
}