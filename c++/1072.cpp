// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// ll x,y,z;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> x >> y;
//     ll s=0,e=x,mid;
//     z=y*100/x;
//     if(z>98){cout << -1; return 0;}
//     while(s<=e){
//         mid=(s+e)/2;
//         if((y+mid)*100/(x+mid)>z) e=mid-1;
//         else s=mid+1;
//     }
//     int ans;
//     if((y+s)*100/(x+s)>z) ans=s;
//     else ans=e;
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll x,y;
double z;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> x >> y;
    z=y*100/x;
    if(z>=99){cout << -1; return 0;}
    double wins[]={x*(z+1)-100*y,99-z};
    cout << int(wins[0]/wins[1]+!(floor(wins[0]/wins[1])==wins[0]/wins[1]));
    return 0;
}