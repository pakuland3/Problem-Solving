#include <bits/stdc++.h>
#define SIZE 1000001
typedef long long ll;
using namespace std;

int parent[SIZE];
int vis[SIZE];
int sieve[SIZE];

int getParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    vector<ll> primes;
    for(int i=2;i<1001;i++){
        if(sieve[i]) continue;
        for(int j=i*i;j<1000001;j+=i) sieve[j]=1;
    }
    for(int i=2;i<1000001;i++) if(!sieve[i]) primes.push_back(i);
    for(int tt=0;tt<tc;tt++){
        ll a,b,p;
        cin >> a >> b >> p;
        ll it=b-a+1;
        for(int i=0;i<it;i++) parent[i]=i;
        memset(vis,0,sizeof(vis));
        for(ll &t:primes){
            if(t<p) continue;
            ll s=(a+t-1)/t*t+t;
            while(s<=b){
                unionParent(s-a,s-a-t);
                s+=t;
            }
        }
        // for(ll i=p;i<=it;i++){
        //     ll sq=sqrt(i);
        //     int c=0;
        //     for(int j=2;j<=sq;j++){
        //         if(i%j==0){
        //             c=1;
        //             break;
        //         }
        //     }
        //     if(c) continue;
        //     ll s=a+(a%i?i-a%i:0)+i;
        //     while(s<=b){
        //         unionParent(s-a,s-a-i);
        //         s+=i;
        //     }
        // }
        int cnt=0;
        for(int i=0;i<it;i++) if(!vis[getParent(i)]) vis[getParent(i)]=1,cnt++;
        cout << "Case #" << tt+1 << ": " << cnt << '\n';
    }
    return 0;
}