#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct poi{
    int x,y;
    int n;
    bool operator<(poi &r){
        if(x==r.x) return y<r.y;
        return x<r.x;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<poi> a(3*n);
    for(int i=0;i<3*n;i++){
        a[i].n=i;
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<3*n;i++){
        cout << a[i].n+1 << ' ';
        if(i%3==2) cout << '\n';
    }
    return 0;
}