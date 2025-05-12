#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,b;
    cin >> n >> b;
    vector<pair<int,int>> a(n);
    for(auto &t:a) cin >> t.first >> t.second;
    vector<int> c;
    int ans=0;
    for(int i=0;i<n;i++){
        c.clear();
        c.push_back(a[i].first/2+a[i].second);
        for(int j=0;j<n;j++){
            if(i==j) continue;
            c.push_back(a[j].first+a[j].second);
        }
        sort(c.begin(),c.end());
        int res=0;
        int tmp=b;
        for(int &t:c){
            if(tmp<t) break;
            tmp-=t;
            res++;
        }
        ans=max(ans,res);
    }
    cout << ans;
    return 0;
}