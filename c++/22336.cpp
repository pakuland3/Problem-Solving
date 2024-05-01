#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<pair<int, int>> ans;
    int n,inn;
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        cin >> inn;
        if(inn) ans.push_back({i,j});
    }
    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++){
        cout << ans[i].second << ' ' << ans[i].second << ' ';
        cout << ans[i].first << ' ' << ans[i].first << '\n';
    }
    return 0;
}