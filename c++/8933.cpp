// #include <bits/stdc++.h>
// #define fi first
// #define se second
// #define pii pair<int,int>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int t;
//     cin >> t;
//     while(t--){
//         map<pair<pii,pii>,int> m;
//         int k;
//         string s;
//         cin >> k >> s;
//         if(k>s.length()){
//             cout << "0\n";
//             continue;
//         }
//         int maxi=1;
//         pair<pii,pii> current={{0,0},{0,0}};
//         for(int i=0;i<k;i++){
//             if(s[i]=='A') current.fi.fi++;
//             if(s[i]=='G') current.fi.se++;
//             if(s[i]=='T') current.se.fi++;
//             if(s[i]=='C') current.se.se++;
//         }
//         m[current]=1;
//         for(int i=k;i<s.length();i++){
//             if(s[i-k]=='A') current.fi.fi--;
//             if(s[i-k]=='G') current.fi.se--;
//             if(s[i-k]=='T') current.se.fi--;
//             if(s[i-k]=='C') current.se.se--;
//             if(s[i]=='A') current.fi.fi++;
//             if(s[i]=='G') current.fi.se++;
//             if(s[i]=='T') current.se.fi++;
//             if(s[i]=='C') current.se.se++;
//             if(m.find(current)!=m.end()){
//                 m[current]++;
//                 maxi=max(maxi,m[current]);
//             }
//             else m[current]=1;
//         }
//         cout << maxi << '\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<ll,ll>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        unordered_map<ll,int> um;
        int k;
        string s;
        cin >> k >> s;
        if(k>s.length()){
            cout << "0\n";
            continue;
        }
        int maxi=1;
        pair<pii,pii> current={{0,0},{0,0}};
        for(int i=0;i<k;i++){
            if(s[i]=='A') current.fi.fi++;
            if(s[i]=='G') current.fi.se++;
            if(s[i]=='T') current.se.fi++;
            if(s[i]=='C') current.se.se++;
        }
        ll v=216000000ll*current.fi.fi+360000ll*current.fi.se+600*current.se.fi+current.se.se;
        um[v]=1;
        for(int i=k;i<s.length();i++){
            if(s[i-k]=='A') current.fi.fi--;
            if(s[i-k]=='G') current.fi.se--;
            if(s[i-k]=='T') current.se.fi--;
            if(s[i-k]=='C') current.se.se--;
            if(s[i]=='A') current.fi.fi++;
            if(s[i]=='G') current.fi.se++;
            if(s[i]=='T') current.se.fi++;
            if(s[i]=='C') current.se.se++;
            v=216000000ll*current.fi.fi+360000ll*current.fi.se+600*current.se.fi+current.se.se;
            if(um.find(v)!=um.end()){
                um[v]++;
                maxi=max(maxi,um[v]);
            }
            else um[v]=1;
        }
        cout << maxi << '\n';
    }
    return 0;
}