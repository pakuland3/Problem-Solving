#include <bits/stdc++.h>
using namespace std;

int n;
int arr[51];
int d[51];
int ans=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int a=1;a<n;a++){
        d[a]++; d[a+1]++;
        for(int b=a+2;b<=n;b++){
            double til=(double)(arr[b]-arr[a])/(b-a);
            double c=-til*a+arr[a];
            bool t=true;
            for(int i=a+1;i<b;i++){
                if(til*i+c<=arr[i]){t=false;break;}
            }
            if(t){d[a]++;d[b]++;}
        }
    }
    for(int i=1;i<=n;i++) ans=max(ans,d[i]);
    cout << ans;
}