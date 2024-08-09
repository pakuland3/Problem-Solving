#include <bits/stdc++.h>
#define INF 10001
typedef long long ll;
using namespace std;

struct poi{
    double x,y;
};

double getValue(double x){
    x*=1e5;
    x=floor(x);
    x/=1e5;
    return x;
}

bool solve(poi &a, poi &b, poi &c, double &dis){
    if(getValue((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y))!=dis) return 0;
    double k=a.x!=b.x?getValue((a.y-b.y)/(a.x-b.x)):INF,l=b.x!=c.x?getValue((b.y-c.y)/(b.x-c.x)):INF;
    if(k==INF && l==0) return 1;
    if(l==INF && k==0) return 1;
    k=getValue(k*l);
    if(k==-1) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int tt=0;tt<t;tt++){
        int n;
        cin >> n;
        int ans=0;
        vector<poi> a(n);
        for(poi &p:a) cin >> p.x >> p.y;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(getValue(a[i].x+a[j].x)!=getValue(2*a[k].x) || getValue(a[i].y+a[j].y)!=getValue(2*a[k].y)) continue;
                    double dis=getValue((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
                    for(int l=0;l<n;l++){
                        if(solve(a[i],a[k],a[l],dis)) ans++;
                    }
                }
            }
        }
        cout << "Set #" << tt+1 << ": " << ans/2 << "\n\n";
    }
    return 0;
}