// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int a[4000],b[4000],c[4000],d[4000];
// int n;
// ll res=0;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     cin >> n;
//     for(int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
//     unordered_map<int,int> ab,cd;
//     for(int i=0;i<n;i++) for(int j=0;j<n;j++){
//         if(ab.find(a[i]+b[j])!=ab.end()) ab[a[i]+b[j]]++;
//         else ab[a[i]+b[j]]=1;
//     }
//     for(int i=0;i<n;i++) for(int j=0;j<n;j++){
//         if(cd.find(c[i]+d[j])!=cd.end()) cd[c[i]+d[j]]++;
//         else cd[c[i]+d[j]]=1;
//     }
//     for(auto it=ab.begin();it!=ab.end();it++) if(cd.find(-it->first)!=cd.end()) res+=(ll)min(it->second,cd[-it->first]);
//     cout << res;
//     return 0;
// }

#include <bits/stdc++.h>
#define SIZE 4000
typedef long long ll;
using namespace std;

int a[SIZE],b[SIZE],c[SIZE],d[SIZE];
int ab[SIZE*SIZE],cd[SIZE*SIZE];
int n,idx=0;
ll res=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ab[idx]=a[i]+b[j];
            cd[idx++]=c[i]+d[j];
        }
    }
    sort(ab,ab+n*n);
    sort(cd,cd+n*n);
    for(int i=0;i<n*n;i++){
        int e=ab[i];
        auto l=lower_bound(cd,cd+n*n,-e);
        if(*l==-e){
            auto r=upper_bound(cd,cd+n*n,-e);
            res+=r-l;
        }
    }
    cout << res;
    return 0;
}