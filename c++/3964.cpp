// it is correct but why
// #include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;
// using namespace std;

// ull g(ull a, int b){
//     if(b==1) return a;
//     ull c=g(a,b/2); c*=c;
//     if(b%2) return c*a;
//     return c;
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int tt;
//     cin >> tt;
//     while(tt--){
//         ull n,k;
//         unordered_map<ull,ull> divs,has;
//         cin >> n >> k;
//         ull res=0;
//         ull tmp=k;
//         while(tmp!=1){
//             ull cnt=sqrt(tmp);
//             bool isPrime=1;
//             for(ull i=2;i<=cnt;i++){
//                 if(tmp%i==0){
//                     tmp/=i;
//                     if(divs.find(i)!=divs.end()) divs[i]++;
//                     else divs[i]=1;
//                     isPrime=0;
//                 }
//             }
//             if(isPrime){
//                 if(divs.find(tmp)!=divs.end()) divs[tmp]++;
//                 else divs[tmp]=1;
//                 break;
//             }
//         }
//         for(auto it=divs.begin();it!=divs.end();it++){
//             for(ull i=1;;i++){
//                 ull pp=g(it->first,i);
//                 ull t=n/pp;
//                 if(has.find(it->first)!=has.end()) has[it->first]+=i*(t-t/it->first);
//                 else has[it->first]=i*(t-t/it->first);
//                 if(n/pp<it->first) break;
//             }
//         }
//         ull mini=INT32_MAX;
//         for(auto it=divs.begin();it!=divs.end();it++) mini=min(mini,has[it->first]/it->second);
//         if(mini!=INT32_MAX) res+=mini;
//         cout << res << '\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tt;
    cin >> tt;
    while(tt--){
        ll n,k;
        cin >> n >> k;
        unordered_map<ll,ll> divs;
        ll tmp=k;
        while(tmp!=1){
            ll cnt=sqrt(tmp);
            bool isPrime=1;
            for(ll i=2;i<=cnt;i++){
                if(tmp%i==0){
                    isPrime=0;
                    tmp/=i;
                    if(divs.find(i)!=divs.end()) divs[i]++;
                    else divs[i]=1;
                    break;
                }
            }
            if(isPrime){
                if(divs.find(tmp)!=divs.end()) divs[tmp]++;
                else divs[tmp]=1;
                break;
            }
        }
        ll res=0;
        ll mini=INT64_MAX;
        for(auto it=divs.begin();it!=divs.end();it++){
            ll t=it->first;
            ll cnt=0;
            while(1){
                cnt+=n/t;
                if(n/it->first<t) break;
                t*=it->first;
            }
            mini=min(mini,cnt/it->second);
        }
        res+=mini;
        cout << res << '\n';
    }
    return 0;
}