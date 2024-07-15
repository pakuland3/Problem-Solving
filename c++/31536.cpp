// TLE
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// struct Poi{
//     ll x,y;
// };

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     vector<Poi> Mat,Kor;
//     int m,k;
//     int x,y,l;
//     cin >> x >> y >> l >> x >> y >> l;
//     cin >> m >> k;
//     for(int i=0;i<m+k;i++){
//         int px,py;
//         cin >> px >> py;
//         if(x<=px && px<=x+l && y<=py && py<=y+l) Kor.push_back({(ll)px,(ll)py});
//         else Mat.push_back({(ll)px,(ll)py});
//     }
//     ll dis=1e13;
//     Poi a,b;    
//     for(int i=0;i<m;i++){
//         for(int j=0;j<k;j++){
//             ll d=(Mat[i].x-Kor[j].x)*(Mat[i].x-Kor[j].x)+(Mat[i].y-Kor[j].y)*(Mat[i].y-Kor[j].y);
//             if(dis>d){
//                 dis=d;
//                 a=Mat[i];
//                 b=Kor[j];
//             }
//         }
//     }
//     cout << dis << '\n';
//     cout << a.x << ' ' << a.y << '\n';
//     cout << b.x << ' ' << b.y;
//     return 0;
// }

// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// struct Poi{
//     ll x,y;
// };

// bool sortbyx(Poi &l, Poi &r){
//     return l.x<r.x;
// };

// bool sortbyy(Poi &l, Poi &r){
//     return l.y<r.y;
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     Poi Ma,Ko;
//     ll a,b,dis,stxM,stxK,styM,styK;
//     cin >> Ma.x >> Ma.y >> a;
//     cin >> Ko.x >> Ko.y >> b;
//     int m,k;
//     cin >> m >> k;
//     vector<Poi> Mxp,Myp,Kxp,Kyp;
//     for(int i=0;i<m+k;i++){
//         int x,y;
//         cin >> x >> y;
//         if(Ma.x<=x && x<=Ma.x+a && Ma.y<=y && y<=Ma.y+a){
//             Mxp.push_back({x,y});
//             Myp.push_back({x,y});
//         }
//         else{
//             Kxp.push_back({x,y});
//             Kyp.push_back({x,y});
//         }
//     }
//     ll ans=(ll)8e15;
//     Poi c,d;
//     sort(Mxp.begin(),Mxp.end(),sortbyx);
//     sort(Kxp.begin(),Kxp.end(),sortbyx);
//     sort(Myp.begin(),Myp.end(),sortbyy);
//     sort(Kyp.begin(),Kyp.end(),sortbyy);
//     int dx[]={1,-1},startM[]={0,m-1},endM[]={m,-1};
//     int startK[]={0,k-1},endK[]={k,-1};
//     for(int i=0;i<2;i++){
//         stxM=Mxp[startM[i]].x;
//         for(int j=startM[i];j*dx[i]<endM[i];j+=dx[i]){
//             if(Mxp[j].x*dx[i]>stxM) break;
//             for(int l=0;l<2;l++){
//                 stxK=Kxp[startK[l]].x;
//                 for(int n=startK[l];n*dx[l]<endK[l];n+=dx[l]){
//                     if(Kxp[n].x*dx[l]>stxK) break;
//                     dis=(Mxp[j].x-Kxp[n].x)*(Mxp[j].x-Kxp[n].x)+(Mxp[j].y-Kxp[n].y)*(Mxp[j].y-Kxp[n].y);
//                     if(dis<ans){
//                         ans=dis;
//                         c=Mxp[j];
//                         d=Kxp[n];
//                     }
//                 }
//             }
//             for(int l=0;l<2;l++){
//                 styK=Kyp[startK[l]].y;
//                 for(int n=startK[l];n*dx[l]<endK[l];n+=dx[l]){
//                     if(Kyp[n].y*dx[l]>styK) break;
//                     dis=(Mxp[j].x-Kyp[n].x)*(Mxp[j].x-Kyp[n].x)+(Mxp[j].y-Kyp[n].y)*(Myp[j].y-Kyp[n].y);
//                     if(dis<ans){
//                         ans=dis;
//                         c=Mxp[j];
//                         d=Kyp[n];
//                     }
//                 }
//             }
//         }
//     }
//     for(int i=0;i<2;i++){
//         styM=Myp[startM[i]].y;
//         for(int j=startM[i];j*dx[i]<endM[i];j+=dx[i]){
//             if(Myp[j].y*dx[i]>styM) break;
//             for(int l=0;l<2;l++){
//                 stxK=Kxp[startK[l]].x;
//                 for(int n=startK[l];n*dx[l]<endK[l];n+=dx[l]){
//                     if(Kxp[n].x*dx[l]>stxK) break;
//                     dis=(Myp[j].x-Kxp[n].x)*(Myp[j].x-Kxp[n].x)+(Myp[j].y-Kxp[n].y)*(Myp[j].y-Kxp[n].y);
//                     if(dis<ans){
//                         ans=dis;
//                         c=Myp[j];
//                         d=Kxp[n];
//                     }
//                 }
//             }
//             for(int l=0;l<2;l++){
//                 styK=Kyp[startK[l]].y;
//                 for(int n=startK[l];n*dx[l]<endK[l];n+=dx[l]){
//                     if(Kyp[n].y*dx[l]>styK) break;
//                     dis=(Myp[j].x-Kyp[n].x)*(Myp[j].x-Kyp[n].x)+(Myp[j].y-Kyp[n].y)*(Myp[j].y-Kyp[n].y);
//                     if(dis<ans){
//                         ans=dis;
//                         c=Myp[j];
//                         d=Kyp[n];
//                     }
//                 }
//             }
//         }
//     }
//     cout << ans << '\n';
//     cout << c.x << ' ' << c.y << '\n';
//     cout << d.x << ' ' << d.y;
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Poi{
    ll x,y;
};

struct info{
    Poi p;
    ll minx=1e8,maxx=-1e8,miny=minx,maxy=maxy;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    info ma,ko;
    ll a,b;
    vector<ll> maax[1001],koox[1001],maay[1001],kooy[1001];
    int m,k;
    cin >> ma.p.x >> ma.p.y >> a >> ko.p.x >> ko.p.y >> b;
    cin >> m >> k;
    for(int i=0;i<m+k;i++){
        ll x,y;
        cin >> x >> y;
        if(ma.p.x<=x && x<=ma.p.x+a && ma.p.y<=y && y<=ma.p.y+a){
            maax[x-ma.p.x].push_back(y);
            maay[y-ma.p.y].push_back(x);
            ma.minx=min(ma.minx,x);
            ma.maxx=max(ma.maxx,x);
            ma.miny=min(ma.miny,y);
            ma.maxy=max(ma.maxy,y);
        }
        else{
            koox[x-ko.p.x].push_back(y);
            kooy[y-ko.p.y].push_back(x);
            ko.minx=min(ko.minx,x);
            ko.maxx=max(ko.maxx,x);
            ko.miny=min(ko.miny,y);
            ko.maxy=max(ko.maxy,y);
        }
    }
    ll ans=1e17,dis;
    Poi c,d;
    if(ma.maxx<ko.minx){
        for(int i=0;i<=b;i++) if(kooy[i].size()>1) sort(kooy[i].begin(),kooy[i].end(),less<ll>());
        for(int i=0;i<=a;i++){
            if(maay[i].size()<1) continue;
            if(maay[i].size()>1) sort(maay[i].begin(),maay[i].end(),greater<ll>());
            for(int j=0;j<=b;j++){
                if(kooy[j].size()<1) continue;
                dis=(maay[i][0]-kooy[j][0])*(maay[i][0]-kooy[j][0])+(ma.p.y+i-ko.p.y-j)*(ma.p.y+i-ko.p.y-j);
                if(dis<ans){
                    ans=dis;
                    c={maay[i][0],i+ma.p.y};
                    d={kooy[j][0],j+ko.p.y};
                }
            }
        }
        cout << ans << '\n';
        cout << c.x << ' ' << c.y << '\n';
        cout << d.x << ' ' << d.y;
        return 0;
    }
    if(ko.maxx<ma.minx){
        for(int i=0;i<=b;i++) if(kooy[i].size()>1) sort(kooy[i].begin(),kooy[i].end(),greater<ll>());
        for(int i=0;i<=a;i++){
            if(maay[i].size()<1) continue; 
            if(maay[i].size()>1) sort(maay[i].begin(),maay[i].end(),less<ll>());
            for(int j=0;j<=b;j++){
                if(kooy[j].size()<1) continue;
                dis=(maay[i][0]-kooy[j][0])*(maay[i][0]-kooy[j][0])+(ma.p.y+i-ko.p.y-j)*(ma.p.y+i-ko.p.y-j);
                if(dis<ans){
                    ans=dis;
                    c={maay[i][0],i+ma.p.y};
                    d={kooy[j][0],j+ko.p.y};
                }
            }
        }
        cout << ans << '\n';
        cout << c.x << ' ' << c.y << '\n';
        cout << d.x << ' ' << d.y;
        return 0;
    }
    if(ma.maxy<ko.miny){
        for(int i=0;i<=b;i++) if(koox[i].size()>1) sort(koox[i].begin(),koox[i].end(),less<ll>());
        for(int i=0;i<=a;i++){
            if(maax[i].size()<1) continue; 
            if(maax[i].size()>1) sort(maax[i].begin(),maax[i].end(),greater<ll>());
            for(int j=0;j<=b;j++){
                if(koox[j].size()<1) continue;
                dis=(maax[i][0]-koox[j][0])*(maax[i][0]-koox[j][0])+(ma.p.x+i-ko.p.x-j)*(ma.p.x+i-ko.p.x-j);
                if(dis<ans){
                    ans=dis;
                    c={i+ma.p.x,maax[i][0]};
                    d={j+ko.p.x,koox[j][0]};
                }
            }
        }
        cout << ans << '\n';
        cout << c.x << ' ' << c.y << '\n';
        cout << d.x << ' ' << d.y;
        return 0;
    }
    for(int i=0;i<=b;i++) if(koox[i].size()>1) sort(koox[i].begin(),koox[i].end(),greater<ll>());
    for(int i=0;i<=a;i++){
        if(maax[i].size()<1) continue; 
        if(maax[i].size()>1) sort(maax[i].begin(),maax[i].end(),less<ll>());
        for(int j=0;j<=b;j++){
            if(koox[j].size()<1) continue;
            dis=(maax[i][0]-koox[j][0])*(maax[i][0]-koox[j][0])+(ma.p.x+i-ko.p.x-j)*(ma.p.x+i-ko.p.x-j);
            if(dis<ans){
                ans=dis;
                c={i+ma.p.x,maax[i][0]};
                d={j+ko.p.x,koox[j][0]};
            }
        }
    }
    cout << ans << '\n';
    cout << c.x << ' ' << c.y << '\n';
    cout << d.x << ' ' << d.y;
    return 0;
}