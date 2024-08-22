#include <bits/stdc++.h>
#define SIZE 1001*1001
typedef long long ll;
using namespace std;

struct poi{
    int x,y;
};

struct info{
    poi p;
    int x,y,nx=1000001,ny=nx,mx=-nx,my=mx;
};

void update(info &a, poi &b){
    a.nx=min(a.nx,b.x);
    a.ny=min(a.ny,b.y);
    a.mx=max(a.mx,b.x);
    a.my=max(a.my,b.y);
}

bool sx(poi &l, poi &r){ return l.x<r.x; }

bool sy(poi &l, poi &r){ return l.y<r.y; }

ll getDis(poi &l, poi &r){
    ll h=l.x,i=l.y,j=r.x,k=r.y;
    return (h-j)*(h-j)+(i-k)*(i-k);
}

poi e,f;
ll ans=1e13,dis;
info ma,ko;
poi maa[SIZE],koo[SIZE];
int a,b,m,k;
bool c[1001],d[1001];
vector<poi> can;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> ma.x >> ma.y >> a >> ko.x >> ko.y >> b;
    cin >> m >> k;
    for(int i=0;i<m;i++){
        cin >> maa[i].x >> maa[i].y;
        update(ma,maa[i]);
    }
    for(int i=0;i<k;i++){
        cin >> koo[i].x >> koo[i].y;
        update(ko,koo[i]);
    }
    if(ma.mx<ko.nx){
        sort(maa,maa+m,sx);
        sort(koo,koo+k,sx);
        for(int i=m-1;i>=0;i--){
            if(c[maa[i].y-ma.y]) continue;
            c[maa[i].y-ma.y]=1;
            can.push_back(maa[i]);
        }
        for(int i=0;i<k;i++){
            if(d[koo[i].y-ko.y]) continue;
            d[koo[i].y-ko.y]=1;
            for(int j=0;j<can.size();j++){
                dis=getDis(can[j],koo[i]);
                if(ans>dis){
                    ans=dis;
                    e=can[j];
                    f=koo[i];
                }
            }
        }
    }
    else if(ko.mx<ma.nx){
        sort(maa,maa+m,sx);
        sort(koo,koo+k,sx);
        for(int i=0;i<m;i++){
            if(c[maa[i].y-ma.y]) continue;
            c[maa[i].y-ma.y]=1;
            can.push_back(maa[i]);
        }
        for(int i=k-1;i>=0;i--){
            if(d[koo[i].y-ko.y]) continue;
            d[koo[i].y-ko.y]=1;
            for(int j=0;j<can.size();j++){
                dis=getDis(can[j],koo[i]);
                if(ans>dis){
                    ans=dis;
                    e=can[j];
                    f=koo[i];
                }
            }
        }
    }
    else if(ma.my<ko.ny){
        sort(maa,maa+m,sy);
        sort(koo,koo+k,sy);
        for(int i=m-1;i>=0;i--){
            if(c[maa[i].x-ma.x]) continue;
            c[maa[i].x-ma.x]=1;
            can.push_back(maa[i]);
        }
        for(int i=0;i<k;i++){
            if(d[koo[i].x-ko.x]) continue;
            d[koo[i].x-ko.x]=1;
            for(int j=0;j<can.size();j++){
                dis=getDis(can[j],koo[i]);
                if(ans>dis){
                    ans=dis;
                    e=can[j];
                    f=koo[i];
                }
            }
        }
    }
    else{
        sort(maa,maa+m,sy);
        sort(koo,koo+k,sy);
        for(int i=0;i<m;i++){
            if(c[maa[i].x-ma.x]) continue;
            c[maa[i].x-ma.x]=1;
            can.push_back(maa[i]);
        }
        for(int i=k-1;i>=0;i--){
            if(d[koo[i].x-ko.x]) continue;
            d[koo[i].x-ko.x]=1;
            for(int j=0;j<can.size();j++){
                dis=getDis(can[j],koo[i]);
                if(ans>dis){
                    ans=dis;
                    e=can[j];
                    f=koo[i];
                }
            }
        }
    }
    cout << ans << '\n';
    cout << e.x << ' ' << e.y << '\n';
    cout << f.x << ' ' << f.y;
    return 0;
}