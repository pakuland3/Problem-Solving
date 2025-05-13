#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[4],b[4],c[4];

int flag;

int cal(int *a, int *b){
    int sa=0,sb=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i]>b[j]) sa++;
            if(a[i]<b[j]) sb++;
        }
    }
    if(sa>sb) return 1;
    if(sa==sb) return 0;
    return -1;
}

void solve(int idx){
    if(flag) return;
    if(idx==4){
        if(cal(a,b)*cal(a,c)==-1 && cal(b,a)*cal(b,c)==-1 && cal(c,a)*cal(c,b)==-1) flag=1;
        return;
    }
    for(int i=1;i<11;i++){
        c[idx]=i;
        solve(idx+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<4;i++) cin >> a[i];
        for(int i=0;i<4;i++) cin >> b[i];
        flag=0;
        solve(0);
        cout << (flag?"yes":"no") << '\n';
    }
    return 0;
}