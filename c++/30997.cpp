// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int n,a,b,c,k;
//     ll m;
//     cin >> n >> m >> k;
//     vector<ll> ct(n,0);
//     for(int i=1;i<m;i++){
//         cin >> a >> b >> c;
//         ct[--a]++; ct[--b]++; ct[--c]++;
//     }
//     ll f=0,g=1;
//     for(int i=0;i<n-2;i++){
//         for(int j=i+1;j<n-1;j++){
//             for(int p=j+1;p<n;p++){
//                 ll d=3ll*m-(ct[i]+ct[j]+ct[p]+3ll),e=3ll*m,div;
//                 for(int h=1;h<k;h++){
//                     d*=3ll*m-(ct[i]+ct[j]+ct[p]+3ll);
//                     e*=3ll*m;
//                 }
//                 d*=ct[i]+ct[j]+ct[p]+3ll;
//                 e*=3ll*m;
//                 div=gcd(d,e);
//                 d/=div; e/=div;
//                 if(f*e<d*g){
//                     f=d;
//                     g=e;
//                     a=i;
//                     b=j;
//                     c=p;
//                 }
//             }
//         }
//     }
//     cout << f << ' ' << g << '\n';
//     cout << a+1 << ' ' << b+1 << ' ' << c+1;
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,kk;
ll m,cnt[101];

ll f(int a){ return cnt[a]+1ll; }

void solve(ll &a, ll &b){
    ll g=gcd(a,b);
    if(g<2) return;
    a/=g;
    b/=g;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> kk;
    int num;
    for(int i=3;i<3*m;i++){
        cin >> num;
        cnt[num]++;
    }
    ll p=-1,q,top,bottom;
    int a,b,c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i==j || j==k || i==k) continue;
                top=1;
                bottom=1;
                for(int l=0;l<kk;l++){
                    top*=3*m-f(i)-f(j)-f(k);
                    bottom*=3*m;
                    solve(top,bottom);
                }
                top*=f(i)+f(j)+f(k);
                bottom*=3*m;
                solve(top,bottom);
                if(p==-1 || top/(double)bottom>p/(double)q){
                    p=top;
                    q=bottom;
                    a=i;
                    b=j;
                    c=k;
                }
            }
        }
    }
    solve(p,q);
    cout << p << ' ' << q << '\n';
    cout << a << ' ' << b << ' ' << c;
    return 0;
}