#include <bits/stdc++.h>
using namespace std;

int t,n,x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int tt=0;tt<t;tt++){
        cin >> x >> n;
        int quoti=x/n;
        int remai=x%n;
        int ans=1;
        while(quoti!=1){
            if(remai%quoti==0){
                ans=quoti;
                break;
            }
            quoti--;
            remai+=n;
        }
        cout << ans << '\n';
    }
}