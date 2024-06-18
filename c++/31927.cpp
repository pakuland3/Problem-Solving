// nice try but wrong answer
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int n;
//     cin >> n;
//     vector<int> a(n); for(int &t:a) cin >> t;
//     vector<int> c(a);
//     vector<pair<int,int>> ans;
//     int cnt=0;
//     for(int i=1;i<n;i++) for(int j=0;j<n;j++){
//         if(i==j) continue;
//         if(a[i]>a[i-1]){
//             bool b=0;
//             int tmp;
//             if(j==0 && a[j+1]<=a[j]+a[i]-a[i-1]){
//                 ans.push_back({j,i});
//                 tmp=a[i-1];
//                 a[j]+=a[i]-a[i-1];
//                 a[i]=tmp;
//                 b=1;
//             }
//             else if(j==n-1 && a[j]+a[i]-a[i-1]<=a[j-1]){
//                 ans.push_back({j,i});
//                 tmp=a[i-1];
//                 a[j]+=a[i]-a[i-1];
//                 a[i]=tmp;
//                 b=1;
//             }
//             else if(a[j+1]<=a[j]+a[i]-a[i-1] && a[j]+a[i]-a[i-1]<=a[j-1]){
//                 ans.push_back({j,i});
//                 tmp=a[i-1];
//                 a[j]+=a[i]-a[i-1];
//                 a[i]=tmp;
//                 b=1;
//             }
//             if(b){cnt++; break;}
//         }
//     }
//     bool b=0;
//     if(cnt>n/2){cout << -1; return 0;}
//     for(int i=1;i<n;i++) if(a[i]>a[i-1]){b=1; break;}
//     if(b) cout << -1;
//     else{
//         cout << cnt << '\n';
//         for(int i=0;i<cnt;i++){
//             c[ans[i].first]+=c[ans[i].second]-c[ans[i].second-1];
//             c[ans[i].second]=c[ans[i].second-1];
//             for(int j=0;j<n;j++) cout << c[j] << ' ';
//             cout << '\n';
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    bool b=1;
    cin >> n;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    cout << n/2 << '\n';
    for(int i=0;i<n/2;i++){
        a[i]+=1e6-5000*i;
        a[n-(i+1)]-=1e6-5000*i;
        for(int j=0;j<n;j++) cout << a[j] << ' ';
        cout << '\n';
    }
    return 0;
}