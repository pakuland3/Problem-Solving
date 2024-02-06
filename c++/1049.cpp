#include <bits/stdc++.h>
using namespace std;

int n,m;
int inn;
int sp,pp;
int ans=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    cin >> sp >> pp;
    for(int i=1;i<m;i++){cin >> inn;sp=min(sp,inn);cin >> inn;pp=min(pp,inn);}
    while(n>0){
        if(n>6 && sp<pp*6){ans+=(n/6)*sp;n-=(n/6)*6;}
        else if(n<=6 && sp<pp*n){ans+=sp;n=0;}
        else if(n<=6 && sp>=pp*n){ans+=pp*n;n=0;}
        else if(sp>=pp*6){ans+=n*pp;n=0;}
    }
    cout << ans;
}