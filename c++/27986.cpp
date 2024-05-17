// #include <bits/stdc++.h>
// #define f first
// #define s second
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int n,m,k;
//     cin >> n >> m;
//     vector<int> arr(n+1,-1);
//     vector<pair<int, int>> parr(m);
//     for(pair<int, int> &p:parr){cin >> p.f >> p.s;}
//     sort(parr.begin(),parr.end(),[](pair<int, int> l, pair<int, int> r)->bool{return l.s-l.f<r.s-r.f;});
//     k=parr[0].s-parr[0].f+1;
//     for(int i=0;i<m;i++){
//         pair<int, int> tp=parr[i];
//         vector<int> req;
//         vector<bool> checking(k+1,0);
//         int pt=0;
//         for(int j=tp.f;j<=tp.s;j++) if(arr[j]!=-1) checking[arr[j]]=1;
//         for(int j=1;j<=k;j++) if(!checking[j]) req.push_back(j);
//         for(int j=tp.f;j<=tp.s;j++){
//             if(pt==req.size()) break;
//             if(arr[j]==-1) arr[j]=req[pt++];
//         }
//     }
//     for(int i=1;i<=n;i++) (arr[i]!=-1)?cout << arr[i] << ' ':cout << "1 ";
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    ll s=0,tmp,x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll &t:a) cin >> t;
    for(int i=0;i<n;i++){cin >> tmp; s+=tmp; if(s<a[i]){cout << -1; return 0;}}
    cout << (s-a[n-1])/x;
    return 0;
}