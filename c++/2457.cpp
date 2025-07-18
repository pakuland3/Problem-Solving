#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct itv{
    int a,b,c,d,vis;
};

itv t[100001];

int f(itv &i, int b){ return 32*(b?i.c:i.a)+(b?i.d:i.b); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int res=0;
    for(int i=0;i<n;i++) cin >> t[i].a >> t[i].b >> t[i].c >> t[i].d;
    sort(t,t+n,[&](itv l, itv r) -> bool { return f(l,0)<f(r,0); });
    itv cur={3,1,0,0};
    int j=0;
    for(int i=0;i<365;i++){
        int idx=-1;
        while(j<n && f(t[j],0)<=f(cur,0)){
            if(idx==-1) idx=j;
            else if(f(t[idx],1)<f(t[j],1)) idx=j;
            j++;
        }
        if(idx==-1) break;
        t[idx].vis=1;
        cur={t[idx].c,t[idx].d,0,0};
        ++res;
        if(f(cur,0)>382) break;
    }
    cout << (!res || f(cur,0)<383?0:res);
    return 0;
}