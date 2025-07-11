#include <bits/stdc++.h>
#define fi first
#define se second
typedef long double ld;
typedef long long ll;
using namespace std;

int r,n,deg,mn,sc;
int vis[360][60][60];

ld solve(pair<int,pair<int,int>> &pre, pair<int,pair<int,int>> &cur){
    int s=cur.se.se-pre.se.se;
    int m=cur.se.fi-pre.se.fi-(s<0);
    int d=cur.fi-pre.fi-(m<0);
    if(s<0) s+=60;
    if(m<0) m+=60;
    ld t=d+(ld)m/60+(ld)s/3600;
    return t/360*3.1415926535*r*r;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc,c1,c2;
    // freopen("../../Biggest Slice/secret/random.ans","r",stdin);
    // vector<ld> res;
    // ld ini;
    // while(cin >> ini) res.push_back(ini);
    // cin.clear();
    // freopen("../../Biggest Slice/secret/random.in","r",stdin);
    cin >> tc;
    for(int c=0;c<tc;c++){
        cin >> r >> n >> deg >> mn >> sc;
        memset(vis,0,sizeof(vis));
        pair<int,pair<int,int>> cur={0,{0,0}};
        vector<pair<int,pair<int,int>>> v;
        v.push_back(cur);
        vis[0][0][0]=1;
        n=min(n,1296000);
        for(int i=1;i<n;i++){
            cur.se.se+=sc;
            c1=(cur.se.se>59);
            cur.se.fi+=mn+c1;
            c2=(cur.se.fi>59);
            cur.fi+=deg+c2;
            if(c1) cur.se.se%=60;
            if(c2) cur.se.fi%=60;
            if(cur.fi>359) cur.fi%=360;
            if(vis[cur.fi][cur.se.fi][cur.se.se]) break;
            v.push_back(cur);
            vis[cur.fi][cur.se.fi][cur.se.se]=1;
        }
        if(v.size()==1){
            cout << fixed << setprecision(6) << r*r*3.1415926535 << '\n';
            // cout << (abs(r*r*3.1415926535-res[c])<1e-4);
            continue;
        }
        sort(v.begin(),v.end(),[&](auto &l, auto &r) -> bool {
            return l.fi==r.fi?(l.se.fi==r.se.fi?l.se.se<r.se.se:l.se.fi<r.se.fi):l.fi<r.fi;
        });
        ld ans=0;
        for(int i=1;i<v.size();i++) ans=max(ans,solve(v[i-1],v[i]));
        v.push_back({v[0].fi+360,v[0].se});
        cout << fixed << setprecision(6) << max(ans,solve(v[v.size()-2],v.back())) << '\n';
        // cout << (abs(res[c]-max(ans,solve(v[v.size()-2],v.back())))<1e-4);
    }
    return 0;
}