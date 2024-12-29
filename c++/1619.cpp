#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    int x,y;
};

int ccw(p &a, p &b, p &c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    p a[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i].x >> a[i].y;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cnt=0;
            for(int k=0;k<n;k++){
                if(k==i || k==j) continue;
                if(ccw(a[i],a[j],a[k])==0) cnt++;
            }
            ans=max(ans,cnt);
        }
    }
    cout << (ans==0?-1:ans+2);
    return 0;
}