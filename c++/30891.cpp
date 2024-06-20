#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct poi{
    double x,y;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,r;
    cin >> n >> r;
    vector<poi> a(n);
    for(auto &p:a) cin >> p.x >> p.y;
    int ans=0;
    poi ans_poi;
    for(double i=-100;i<101;i++){
        for(double j=-100;j<101;j++){
            int cnt=0;
            for(int k=0;k<n;k++){
                if(pow((i-a[k].x),2)+pow(j-a[k].y,2)<=r*r) cnt++;
            }
            if(ans<cnt){
                ans_poi.x=i;
                ans_poi.y=j;
                ans=cnt;
            }
        }
    }
    cout << ans_poi.x << ' ' << ans_poi.y;
    return 0;
}