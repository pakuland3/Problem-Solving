#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    vector<int> b(a);
    ll res=0;
    sort(b.begin(),b.end());
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]<b[i]){
                res+=b[i]-a[j];
                for(int dx:{1,-1}){
                    for(int k=1;0<=j+dx*k && j+dx*k<n;k++){
                        if(a[j+dx*k]!=a[j]) break;
                        a[j+dx*k]=b[i];
                    }
                }
                a[j]=b[i];
            }
        }
    }
    cout << res;
    return 0;
}

// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     freopen("0205.in","w",stdout);
//     cout << 1000 << '\n';
//     for(int i=1;i<=1000;++i)
//     {
//     if (i%2) cout << "1\n";
//         else cout << "1000000000\n";
//     }
//     return 0;
// }