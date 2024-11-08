// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// ll sieve[1000001];

// ll solve(ll a, int b){
//     if(b==1) return a;
//     if(b==0) return 1;
//     ll k=solve(a,b/2);
//     k*=k;
//     if(b%2) k*=a;
//     return k; 
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     for(int i=2;i<=1000;i++){
//         if(sieve[i]!=0) continue;
//         sieve[i]=i;
//         for(int j=i*i;j<=1000000;j+=i) sieve[j]=i;
//     }
//     ll ans=1;
//     unordered_map<ll,int> um;
//     ll n;
//     cin >> n;
//     while(n!=1){
//         if(n<1000001){
//             if(sieve[n]==0) sieve[n]=n;
//             if(um.find(sieve[n])!=um.end()) um[sieve[n]]++;
//             else um[sieve[n]]=1;
//             n/=sieve[n];
//             continue;
//         }
//         int cnt=sqrt(n);
//         bool isDiv=0;
//         for(int i=2;i<=cnt;i++){
//             if(n%i==0){
//                 isDiv=1;
//                 if(um.find(i)!=um.end()) um[i]++;
//                 else um[i]=1;
//                 n/=i;
//                 break;
//             }
//         }
//         if(!isDiv){
//             if(um.find(n)!=um.end()) um[n]++;
//             else um[n]=1;
//             n=1;
//         }
//     }
//     for(auto p:um){
//         ll k=solve(p.first,p.second);
//         ans*=k-k/p.first;
//     }
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    ll res=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i) continue;
        res-=res/i;
        while(n%i==0) n/=i;
    }
    if(n>1) res-=res/n;
    cout << res;
    return 0;
}