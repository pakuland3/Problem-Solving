#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    int x,y;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<p> a(n);
    for(p &t:a) cin >> t.x >> t.y;
    sort(a.begin(),a.end(),[&](p &a, p &b) -> bool { return a.x<b.x; });
    int ans=INT32_MAX;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            vector<int> y;
            for(int k=i;k<=j;k++) y.push_back(a[k].y);
            if(y.size()<n/2) continue;
            sort(y.begin(),y.end());
            for(int k=0;k<=y.size()-n/2;k++) ans=min(ans,(y[k+n/2-1]-y[k]+2)*(a[j].x-a[i].x+2));
        }
    }
    cout << ans;
    return 0;
}