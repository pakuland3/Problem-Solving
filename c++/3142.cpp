#include <bits/stdc++.h>
#define MAX 1000001
typedef long long ll;
using namespace std;

int cnt,x;
int sieve[MAX];
bool d[MAX];

void solve(){
    for(cin >> x;x!=1;x/=sieve[x]){
        d[sieve[x]]=!d[sieve[x]];
        if(d[sieve[x]]) cnt++;
        else cnt--;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i=2;i<MAX;i++){
        if(sieve[i]) continue;
        sieve[i]=i;
        if((ll)i*(ll)i>(ll)MAX) continue;
        for(int j=i*i;j<MAX;j+=i) sieve[j]=i;
    }
    int n;
    cin >> n;
    while(n--){
        solve();
        if(cnt==0) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}