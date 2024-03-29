// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;
// 오목 다각형을 처리하지 못하는 이슈
// int n;
// double ans=0;

// void solve(pair<ll, ll> p[3]){
//     double a=sqrt((p[0].first-p[1].first)*(p[0].first-p[1].first)+(p[0].second-p[1].second)*(p[0].second-p[1].second));
//     double b=sqrt((p[1].first-p[2].first)*(p[1].first-p[2].first)+(p[1].second-p[2].second)*(p[1].second-p[2].second));
//     double c=sqrt((p[0].first-p[2].first)*(p[0].first-p[2].first)+(p[0].second-p[2].second)*(p[0].second-p[2].second));
//     double sin_C=sqrt(1-(a*a+b*b-c*c)*(a*a+b*b-c*c)/(4*a*a*b*b));
//     if(p[0].first<p[1].first){ans-=a*b*sin_C/2;return;}
//     ans+=a*b*sin_C/2;
//     return;
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> n; vector<pair<ll, ll>> arr(n);
//     for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
//     for(int i=0;i<n-2;i++){
//         pair<ll, ll> tt[3];
//         tt[0].first=arr[0].first; tt[0].second=arr[0].second;
//         for(int j=1;j<3;j++){tt[j].first=arr[i+j].first; tt[j].second=arr[i+j].second;}
//         solve(tt);
//     }
//     ans=round(ans*10)/10;
//     cout.precision(1);
//     cout << fixed;
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
double ans=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<ll, ll>> arr(n+1);
    for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second; arr[n]=arr[0];
    for(int i=0;i<n;i++) ans+=arr[i].first*arr[i+1].second;
    for(int i=0;i<n;i++) ans-=arr[i].second*arr[i+1].first;
    ans=round(ans*5)/10;
    cout.precision(1);
    cout << fixed;
    cout << abs(ans);
    return 0;
}