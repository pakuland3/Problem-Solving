#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,p;
    cin >> n >> p;
    vector<int> a(n);
    vector<pair<int,int>> b;
    int last=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i!=0 && a[i]!=a[i-1]+1){
            b.push_back({a[last],a[i-1]});
            last=i;
        }
        if(i==n-1) b.push_back({a[last],a[i]});
    }
    int s=0,e=0;
    int ans=b[0].se-b[0].fi+1;
    while(1){
        if(e<b.size()-1 && b[e+1].fi-b[e].se-1<=p){
            p-=b[++e].fi-b[e-1].se-1;
            ans=max(ans,b[e].se-b[s].fi+1+p);
        }
        else{
            s++;
            if(s>e) e++;
            else p+=b[s].fi-b[s-1].se-1;
            if(e==b.size()) break;
            ans=max(ans,b[e].se-b[s].fi+1+p);
        }
    }
    cout << ans;
    return 0;
}