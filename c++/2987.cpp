#include <bits/stdc++.h>
using namespace std;

struct pos{
    int x,y;
};

double getCCW(pos a, pos b, pos c){
    return a.x*b.y+b.x*c.y+c.x*a.x-(b.x*a.y+c.x*b.y+a.x*c.y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ans=0;
    pos A,B,C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    cin >> n;
    vector<pos> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i].x >> arr[i].y;
    double area=getCCW(A,B,C);
    for(int i=0;i<n;i++){
        double ccw;
        if(area<0){
            ccw=getCCW(A,arr[i],B);
            if(abs(ccw)>-area) continue;
            if(ccw>0) continue;
            ccw=getCCW(B,arr[i],C);
            if(abs(ccw)>-area) continue;
            if(ccw>0) continue;
            ccw=getCCW(C,arr[i],A);
            if(abs(ccw)>-area) continue;
            if(ccw<0) continue;
            ans++;
        }
        else{
            
        }
    }
    return 0;
}