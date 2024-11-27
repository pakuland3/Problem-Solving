#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    double x,y;
};

double d(p a, p b){ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    p a,b,c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    double d1=d(a,b),d2=d(b,c),d3=d(a,c);
    if(d1==0 || d2==0 || d3==0 || a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y==0){
        cout << -1;
        return 0;
    }
    cout << 2*(max(d1+d2,max(d2+d3,d1+d3))-min(d1+d2,min(d2+d3,d1+d3)));
    return 0;
}

// #include <bits/stdc++.h>
// #define IMP 1e5
// #define eps 1e-9
// typedef long long ll;
// using namespace std;

// struct p{
//     double x,y;
// };

// double d(p a, p b){ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     cout.precision(10);
//     cout << fixed;
//     p a,b,c;
//     cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
//     double d1=d(a,b),d2=d(b,c),d3=d(a,c);
//     double a1=(a.x!=b.x?(a.y-b.y)/(a.x-b.x):IMP);
//     double a2=(c.x!=b.x?(c.y-b.y)/(c.x-b.x):IMP);
//     if(d1==0 || d2==0 || d3==0 || abs(a1-a2)<eps){
//         cout << -1;
//         return 0;
//     }
//     cout << 2*(max(d1+d2,max(d2+d3,d1+d3))-min(d1+d2,min(d2+d3,d1+d3)));
//     return 0;
// }