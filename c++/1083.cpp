// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int n,s;
//     cin >> n;
//     vector<int> a(n);
//     for(int &t:a) cin >> t;
//     cin >> s;
//     for(int i=0;i<n;i++){
//         int l=0;
//         for(int j=1;i+j<n;j++){
//             if(a[i+j-1]>a[i+j]) break;
//             l++;
//         }
//         l=min(l,s);
//         for(int j=l;j>0;j--) swap(a[i+j],a[i+j-1]);
//         s-=l;
//     }
//     for(int i=0;i<n;i++) cout << a[i] << ' ';
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,s;
    cin >> n;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    cin >> s;
    for(int i=0;i<n;i++){
        int idx=i;
        for(int j=1;j<=s && i+j<n;j++) if(a[i+j]>a[i] && a[i+j]>a[idx]) idx=i+j;
        for(int j=idx-i;j>0;j--) swap(a[i+j],a[i+j-1]);
        s-=idx-i;
    }
    for(int i=0;i<n;i++) cout << a[i] << ' ';
    return 0;
}