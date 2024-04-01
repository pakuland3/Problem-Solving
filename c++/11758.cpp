#include <bits/stdc++.h>
using namespace std;

struct pos{
    int x;
    int y;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    pos a,b,c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    int ans=a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y;
    if(ans>0) cout << 1;
    else if(ans<0) cout << -1;
    else cout << 0;
    return 0;
}