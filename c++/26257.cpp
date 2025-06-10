#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int p[200001],v[200001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1;i<=m;i++) cin >> p[i];
    while(q--){
        string a;
        int x,y;
        cin >> a >> x;
        if(a[0]=='a'){
            cin >> y;
            p[x]=p[y];
        }
        else if(a[0]=='s'){
            cin >> y;
            swap(p[x],p[y]);
        }
        else p[x]=0;
    }
    vector<int> ans;
    for(int i=1;i<=m;i++) if(p[i] && !v[p[i]]){
        ans.push_back(p[i]);
        v[p[i]]=1;
    }
    unique(ans.begin(),ans.end());
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(int &t:ans) cout << t << '\n';
    return 0;
}