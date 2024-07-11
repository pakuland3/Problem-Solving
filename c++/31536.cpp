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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Poi Ma,Ko;
    ll a,b;
    cin >> Ma.x >> Ma.y >> a;
    cin >> Ko.x >> Ko.y >> b;
    int m,k;
    cin >> m >> k;
    vector<Poi> Mp,Kp;
    for(int i=0;i<m+k;i++){
        int x,y;
        cin >> x >> y;
        if(Ma.x<=x && x<=Ma.x+a && Ma.y<=y && y<=Ma.y+a) Mp.push_back({x,y});
        else Kp.push_back({x,y});
    }
    if(Ma.x+a<Ko.x){
        
        return 0;
    }
    
    return 0;
}