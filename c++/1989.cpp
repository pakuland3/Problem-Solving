#include <bits/stdc++.h>
#define FI first
#define SE second
typedef long long ll;
using namespace std;

ll a[100001];

ll s(int L, int R){ return a[R]-a[L-1]; }

pair<ll,pair<int,int>> solve(int L, int R){
    if(L==R) return {s(L,L)*s(R,R),{L,R}};
    int MID=(L+R)/2;
    int left=MID,right=MID+1;
    int S=MID,E=MID+1;
    ll mini=min(s(S,S),s(E,E));
    ll tmp=mini*s(S,E);
    while(L<S || E<R){
        if(L==S){
            E++;
            mini=min(mini,s(E,E));
            ll t=mini*s(S,E);
            if(tmp<t){
                tmp=t;
                left=S;
                right=E;
            }
            continue;
        }
        if(E==R){
            S--;
            mini=min(mini,s(S,S));
            ll t=mini*s(S,E);
            if(tmp<t){
                tmp=t;
                left=S;
                right=E;
            }
            continue;
        }
        int tt=E+1;
        if(s(S-1,S-1)<=s(E+1,E+1)) E++;
        else{
            S--;
            tt=S;
        }
        mini=min(mini,s(tt,tt));
        ll t=mini*s(S,E);
        if(tmp<t){
            tmp=t;
            left=S;
            right=E;
        }
    }
    pair<ll,pair<int,int>> LL=solve(L,MID);
    pair<ll,pair<int,int>> RR=solve(MID+1,E);
    if(LL.FI<RR.FI){
        if(RR.FI<tmp) return {tmp,{left,right}};
        else return RR;
    }
    else{
        if(LL.FI<tmp) return {tmp,{left,right}};
        else return LL;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    pair<ll,pair<ll,ll>> res=solve(1,n);
    cout << res.first << '\n' << res.second.first << ' ' << res.second.second;
    return 0;
}