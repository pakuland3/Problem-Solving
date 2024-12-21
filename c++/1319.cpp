#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    int x,y,v,id;
};

int n;
int sum;
int ans=5e7+1;
vector<p> a;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    a.resize(n);
    for(p &t:a) cin >> t.x >> t.y >> t.v;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int suma=0,sumb=0;
            int tmpa=a[i].v,tmpb=a[j].v;
            bool flag=0;
            for(int k=0;k<n;k++){
                if(k==i || k==j) continue;
                int x1=a[j].x-a[i].x;
                int y1=a[j].y-a[i].y;
                int x2=a[k].x-a[i].x;
                int y2=a[k].y-a[i].y;
                int t=x1*y2-x2*y1;
                int d=x1*x2+y1*y2;
                if(t<0) suma+=a[k].v;
                else if(t>0) sumb+=a[k].v;
                else if(d>0){
                    if(x2*x2+y2*y2<x1*x1+y1*y1) flag=1;
                    tmpb+=a[k].v;
                }
                else tmpa+=a[k].v;
            }
            if(flag) continue;
            ans=min(ans,min(abs(suma+tmpa-sumb-tmpb),abs(suma+tmpb-sumb-tmpa)));
        }
    }
    cout << ans;
    return 0;
}