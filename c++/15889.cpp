#include <bits/stdc++.h>
#define SUBMIT 1
typedef long long ll;
typedef long double ld;
using namespace std;

struct sol{
    int p,r;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<sol> a(n);
    for(int i=0;i<n;i++) cin >> a[i].p;
    for(int i=0;i<n-1;i++) cin >> a[i].r;
    sort(a.begin(),a.end(),[](sol &l, sol &r)->bool{ return l.p<r.p; });
    int cur=0;
    for(int i=0;i<n;i++){
        if(cur<a[i].p){
            cout << "엄마 나 전역 늦어질 것 같아";
            return 0;
        }
        if(i<n-1) cur=max(cur,a[i].p+a[i].r);
    }
    cout << "권병장님, 중대장님이 찾으십니다";
    return 0;
}