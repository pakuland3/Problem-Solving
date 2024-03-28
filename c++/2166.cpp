#include <bits/stdc++.h>
using namespace std;

int n;
double ans=0;

void solve(pair<int, int> p[3]){
    double a=sqrt((p[0].first-p[1].first)*(p[0].first-p[1].first)+(p[0].second-p[1].second)*(p[0].second-p[1].second));
    double b=sqrt((p[1].first-p[2].first)*(p[1].first-p[2].first)+(p[1].second-p[2].second)*(p[1].second-p[2].second));
    double c=sqrt((p[0].first-p[2].first)*(p[0].first-p[2].first)+(p[0].second-p[2].second)*(p[0].second-p[2].second));
    double sin_C=sqrt(1-(a*a+b*b-c*c)*(a*a+b*b-c*c)/(4*a*a*b*b));
    ans+=a*b*sin_C/2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; vector<pair<int, int>> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
    for(int i=0;i<n-2;i++){
        pair<int, int> tt[3];
        tt[0].first=arr[0].first; tt[0].second=arr[0].second;
        for(int j=1;j<3;j++){tt[j].first=arr[i+j].first; tt[j].second=arr[i+j].second;}
        solve(tt);
    }
    ans=round(ans*10)/10;
    cout.precision(1);
    cout << fixed;
    cout << ans;
    return 0;
}