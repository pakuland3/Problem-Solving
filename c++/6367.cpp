#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct rgb{
    int r,g,b;
};

int d(rgb a, rgb b){ return (a.r-b.r)*(a.r-b.r)+(a.g-b.g)*(a.g-b.g)+(a.b-b.b)*(a.b-b.b); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rgb t[16];
    for(int i=0;i<16;i++) cin >> t[i].r >> t[i].g >> t[i].b;
    rgb tt,ans;
    while((cin >> tt.r >> tt.g >> tt.b) && tt.r!=-1){
        int mini=INT32_MAX;
        for(int i=0;i<16;i++){
            if(mini>d(t[i],tt)){
                ans=t[i];
                mini=d(t[i],tt);
            }
        }
        cout << '(' << tt.r << ',' << tt.g << ',' << tt.b << ") maps to (" << ans.r << ',' << ans.g << ',' << ans.b << ")\n";
    }
    return 0;
}