#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    double x,y;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    double ans=100;
    p a[4];
    for(int i=0;i<4;i++) cin >> a[i].x >> a[i].y;
    auto d=[&](p &a, p &b) -> double { return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); };
    for(int i=1;i<4;i++){
        double dis=d(a[0],a[i]);
        for(int j=1;j<4;j++){
            if(i==j) continue;
            dis+=d(a[i],a[j]);
            for(int k=1;k<4;k++){
                if(k==i || k==j) continue;
                dis+=d(a[j],a[k]);
                ans=min(ans,dis);
                dis-=d(a[j],a[k]);
            }
            dis-=d(a[i],a[j]);
        }
    }
    cout << (int)ans;
    return 0;
}