#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    int res=0;
    cin >> n >> k;
    if(k>=n){
        cout << 0;
        return 0;
    }
    a[0]=n;
    while(n>k){
        bool isMerged=0;
        int goal=n-k;
        for(int i=0;i<25;i++){
            if(a[i]>1){
                int c=min(a[i]/2,goal);
                goal-=c;
                a[i]-=c*2;
                a[i+1]+=c;
                n-=c;
                isMerged=1;
            }
        }
        if(!isMerged){
            a[0]++;
            n++;
            res++;
        }
    }
    cout << res;
    return 0;
}