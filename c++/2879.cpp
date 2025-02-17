#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int ans=0;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        a[i]=t-a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>0){
            while(a[i]){
                int v=a[i];
                int j=min(i+1,n-1);
                while(j<n && a[j]>0){
                    v=min(v,a[j]);
                    j++;
                }
                j--;
                for(int k=i;k<=j;k++) a[k]-=v;
                ans+=v;
            }
        }
        else{
            while(a[i]){
                int v=a[i];
                int j=min(i+1,n-1);
                while(j<n && a[j]<0){
                    v=max(v,a[j]);
                    j++;
                }
                j--;
                for(int k=i;k<=j;k++) a[k]-=v;
                ans-=v;
            }
        }
    }
    cout << ans;
    return 0;
}