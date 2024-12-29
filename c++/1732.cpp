#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 100001
#define pii pair<ll,ll>
typedef long long ll;
using namespace std;

struct p{
    ll x,y,z;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<p> a(n);
    map<pii,vector<p>> m;
    for(p &tt:a){
        cin >> tt.x >> tt.y >> tt.z;
        ll t=tt.y,b=tt.x;
        if(b==0){
            if(m.find({INF,0})==m.end()) m[{INF,0}]=vector<p>();
            m[{INF,0}].push_back(tt);
            continue;
        }
        if(t==0){
            int sgn=1;
            if(b<0) sgn*=-1;
            if(m.find({-INF,sgn})==m.end()) m[{-INF,sgn}]=vector<p>();
            m[{-INF,sgn}].push_back(tt);
            continue;
        }
        ll g=gcd(t,b);
        t/=g;
        b/=g;
        if(m.find({b,t})==m.end()) m[{b,t}]=vector<p>();
        m[{b,t}].push_back(tt);
    }
    vector<p> ans;
    for(auto it=m.begin();it!=m.end();it++){
        vector<p> b=it->se;
        sort(b.begin(),b.end(),[&](p &c, p &d) -> bool {
            return abs(c.x)+c.y<abs(d.x)+d.y;
        });
        int h=b[0].z;
        for(int i=1;i<b.size();i++){
            if(b[i].z<=h) ans.push_back(b[i]);
            h=max(h,(int)b[i].z);
        }
    }
    sort(ans.begin(),ans.end(),[&](p &a, p &b) -> bool {
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    });
    for(p &t:ans) cout << t.x << ' ' << t.y << '\n';
    return 0;
}