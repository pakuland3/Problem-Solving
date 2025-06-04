// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int n;
//     ll k;
//     cin >> n >> k;
//     vector<ll> a(n);
//     for(int i=0;i<n;i++){
//         ll x,y;
//         cin >> x >> y;
//         a[i]=x*x+y*y;
//     }
//     sort(a.begin(),a.end());
//     int e=0;
//     int ans=1;
//     for(int s=0;s<n;s++){
//         if(e<s) e=s;
//         while(e<n){
//             ll t=a[e]-a[s]-k*k;
//             if(t>0 && t*t>4*a[s]*k*k) break;
//             e++;
//         }
//         ans=max(ans,e-s);
//     }
//     cout << fixed << setprecision(7) << ans*100/(long double)n;
//     return 0;
// }

// #include <bits/stdc++.h>
// typedef long double ld;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int n;
//     ld k;
//     cin >> n >> k;
//     vector<ld> a(n);
//     for(int i=0;i<n;i++){
//         ld x,y;
//         cin >> x >> y;
//         a[i]=sqrt(x*x+y*y);
//     }
//     sort(a.begin(),a.end());
//     int e=0;
//     int ans=1;
//     for(int s=0;s<n;s++){
//         if(e<s) e=s;
//         while(e<n && a[e]<=a[s]+k) e++;
//         ans=max(ans,e-s);
//     }
//     cout << fixed << setprecision(7) << ans*100/(ld)n;
//     return 0;
// }

#include <bits/stdc++.h>
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    ld k;
    cin >> n >> k;
    vector<pair<ld,int>> a;
    for(int i=0;i<n;i++){
        ld x,y;
        cin >> x >> y;
        ld d=sqrt(x*x+y*y);
        a.push_back({d-k/2,1});
        a.push_back({d+k/2,-1});
    }
    sort(a.begin(),a.end(),[](auto &l, auto &r) -> bool { return l.first<r.first; });
    int ans=1;
    int cur=0;
    for(auto &p:a){
        cur+=p.second;
        ans=max(ans,cur);
    }
    cout << fixed << setprecision(7) << ans*100/(ld)n;
    return 0;
}