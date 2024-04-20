#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m,A,e=0,s=0,mid,sum,tmp;
    cin >> n >> m >> A;
    vector<ll> sc(n); for(int i=0;i<n;i++){cin >> sc[i];e=max(e,sc[i]);}
    ll ans=e;
    sort(sc.begin(),sc.end());
    while(s<=e){
        mid=(s+e)/2;
        tmp=mid;
        sum=0;
        for(int i=0;i<m;i++){
            int ind=lower_bound(sc.begin(),sc.end(),mid)-sc.begin();
            if(mid<sc[ind] && ind>0){sum+=sc[ind-1];mid+=sc[ind-1];}
            else if(ind==n){sum+=sc[n-1];mid+=sc[n-1];}
            else if(mid>=sc[ind]){sum+=sc[ind];mid+=sc[ind];}
        }
        if(sum>=A) e=tmp-1;
        else s=tmp+1;
    }
    sum=0;
    tmp=e;
    for(int i=0;i<m;i++){
        int ind=lower_bound(sc.begin(),sc.end(),e)-sc.begin();
        if(e<sc[ind] && ind>0){sum+=sc[ind-1];e+=sc[ind-1];}
        else if(ind==n){sum+=sc[n-1];mid+=sc[n-1];}
        else if(e>=sc[ind]){sum+=sc[ind];e+=sc[ind];}
    }
    if(sum>=A) ans=tmp;
    cout << min(ans,s);
    return 0;
}