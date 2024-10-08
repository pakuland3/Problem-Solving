// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int n,tmp;
// ll ans=0;
// unordered_map<int,int> um;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     cin >> n;
//     um[1]=n;
//     while(n--){
//         cin >> tmp;
//         if(tmp==1) continue;
//         if(um.find(tmp)!=um.end()) um[tmp]++;
//         else um[tmp]=1;
//         int cnt=sqrt(tmp);
//         for(int i=2;i<=cnt;i++){
//             if(tmp%i==0){
//                 if(um.find(i)!=um.end()) um[i]++;
//                 else um[i]=1;
//                 if(tmp/i!=i){
//                     if(um.find(tmp/i)!=um.end()) um[tmp/i]++;
//                     else um[tmp/i]=1;
//                 }
//             }
//         }
//     }
//     for(auto it=um.begin();it!=um.end();it++){
//         if(it->second!=1) ans=max(ans,(ll)it->first*(ll)it->second);
//     }
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
#define SIZE 2000001
typedef long long ll;
using namespace std;

int n,cnt[SIZE],tmp;
ll ans=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    while(n--){
        cin >> tmp;
        cnt[tmp]++;
    }
    for(int i=1;i<SIZE;i++){
        ll s=0;
        for(int j=1;i*j<SIZE;j++) s+=(ll)cnt[i*j];
        if(s<2) continue;
        ans=max(ans,(ll)i*s);
    }
    cout << ans;
    return 0;
}