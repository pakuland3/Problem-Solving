#include <bits/stdc++.h>
using namespace std;

struct pos{
    int x,y;
};

double getCCW(pos a, pos b, pos c){
    return a.x*b.y+b.x*c.y+c.x*a.y-(b.x*a.y+c.x*b.y+a.x*c.y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ans=0;
    pos A,B,C,tmp;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> n;
    double area=getCCW(A,B,C),ccw;
    for(int i=0;i<n;i++){
        cin >> tmp.x >> tmp.y;
        if(area<0){
            ccw=getCCW(A,tmp,B);
            if(abs(ccw)>-area) continue;
            if(ccw<0) continue;
            ccw=getCCW(B,tmp,C);
            if(abs(ccw)>-area) continue;
            if(ccw<0) continue;
            ccw=getCCW(C,tmp,A);
            if(abs(ccw)>-area) continue;
            if(ccw<0) continue;
            ans++;
        }
        else{
            ccw=getCCW(A,tmp,B);
            if(abs(ccw)>area) continue;
            if(ccw>0) continue;
            ccw=getCCW(B,tmp,C);
            if(abs(ccw)>area) continue;
            if(ccw>0) continue;
            ccw=getCCW(C,tmp,A);
            if(abs(ccw)>area) continue;
            if(ccw>0) continue;
            ans++;
        }
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(area)/2 << '\n' << ans;
    return 0;
}