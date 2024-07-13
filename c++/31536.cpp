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

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Poi{
    ll x,y;
};

bool sortbyx(Poi &l, Poi &r){
    return l.x<r.x;
};

bool sortbyy(Poi &l, Poi &r){
    return l.y<r.y;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Poi Ma,Ko;
    ll a,b,dis,stxM,stxK,styM,styK;
    cin >> Ma.x >> Ma.y >> a;
    cin >> Ko.x >> Ko.y >> b;
    int m,k;
    cin >> m >> k;
    vector<Poi> Mxp,Myp,Kxp,Kyp;
    for(int i=0;i<m+k;i++){
        int x,y;
        cin >> x >> y;
        if(Ma.x<=x && x<=Ma.x+a && Ma.y<=y && y<=Ma.y+a){
            Mxp.push_back({x,y});
            Myp.push_back({x,y});
        }
        else{
            Kxp.push_back({x,y});
            Kyp.push_back({x,y});
        }
    }
    ll ans=(ll)8e15;
    Poi c,d;
    sort(Mxp.begin(),Mxp.end(),sortbyx);
    sort(Kxp.begin(),Kxp.end(),sortbyx);
    sort(Myp.begin(),Myp.end(),sortbyy);
    sort(Kyp.begin(),Kyp.end(),sortbyy);
    int dx[]={1,-1},startM[]={0,m-1},endM[]={m,-1};
    int startK[]={0,k-1},endK[]={k,-1};
    for(int i=0;i<2;i++){
        stxM=Mxp[startM[i]].x;
        for(int j=startM[i];j*dx[i]<endM[i];j+=dx[i]){
            if(Mxp[j].x*dx[i]>stxM) break;
            for(int l=0;l<2;l++){
                stxK=Kxp[startK[l]].x;
                for(int n=startK[l];n*dx[l]<endK[l];n+=dx[l]){
                    if(Kxp[n].x*dx[l]>stxK) break;
                    dis=(Mxp[j].x-Kxp[n].x)*(Mxp[j].x-Kxp[n].x)+(Mxp[j].y-Kxp[n].y)*(Mxp[j].y-Kxp[n].y);
                    if(dis<ans){
                        ans=dis;
                        c=Mxp[j];
                        d=Kxp[n];
                    }
                }
            }
            for(int l=0;l<2;l++){
                styK=Kyp[startK[l]].y;
                for(int n=startK[l];n*dx[l]<endK[l];n+=dx[l]){
                    if(Kyp[n].y*dx[l]>styK) break;
                    dis=(Mxp[j].x-Kyp[n].x)*(Mxp[j].x-Kyp[n].x)+(Mxp[j].y-Kyp[n].y)*(Myp[j].y-Kyp[n].y);
                    if(dis<ans){
                        ans=dis;
                        c=Mxp[j];
                        d=Kyp[n];
                    }
                }
            }
        }
    }
    for(int i=0;i<2;i++){
        styM=Myp[startM[i]].y;
        for(int j=startM[i];j*dx[i]<endM[i];j+=dx[i]){
            if(Myp[j].y*dx[i]>styM) break;
            for(int l=0;l<2;l++){
                stxK=Kxp[startK[l]].x;
                for(int n=startK[l];n*dx[l]<endK[l];n+=dx[l]){
                    if(Kxp[n].x*dx[l]>stxK) break;
                    dis=(Myp[j].x-Kxp[n].x)*(Myp[j].x-Kxp[n].x)+(Myp[j].y-Kxp[n].y)*(Myp[j].y-Kxp[n].y);
                    if(dis<ans){
                        ans=dis;
                        c=Myp[j];
                        d=Kxp[n];
                    }
                }
            }
            for(int l=0;l<2;l++){
                styK=Kyp[startK[l]].y;
                for(int n=startK[l];n*dx[l]<endK[l];n+=dx[l]){
                    if(Kyp[n].y*dx[l]>styK) break;
                    dis=(Myp[j].x-Kyp[n].x)*(Myp[j].x-Kyp[n].x)+(Myp[j].y-Kyp[n].y)*(Myp[j].y-Kyp[n].y);
                    if(dis<ans){
                        ans=dis;
                        c=Myp[j];
                        d=Kyp[n];
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    cout << c.x << ' ' << c.y << '\n';
    cout << d.x << ' ' << d.y;
    return 0;
}