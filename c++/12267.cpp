#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int tt=0;tt<t;tt++){
        int n;
        cin >> n;
        int a[36][36];
        bool vis[36*36];
        for(int i=0;i<n*n;i++) for(int j=0;j<n*n;j++) cin >> a[i][j];
        bool flag=0;
        for(int i=0;i<n*n;i++){
            for(int j=1;j<=n*n;j++) vis[j]=0;
            for(int j=0;j<n*n;j++){
                if(a[i][j]>n*n || vis[a[i][j]]) flag=1;
                vis[a[i][j]]=1;
            }
        }
        for(int i=0;i<n*n;i++){
            for(int j=1;j<=n*n;j++) vis[j]=0;
            for(int j=0;j<n*n;j++){
                if(a[j][i]>n*n || vis[a[j][i]]) flag=1;
                vis[a[j][i]]=1;
            }
        }
        for(int i=0;i<n*n;i+=n){
            for(int j=0;j<n*n;j+=n){
                for(int j=1;j<=n*n;j++) vis[j]=0;
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if(a[i+k][j+l]>n*n || vis[a[i+k][j+l]]) flag=1;
                        vis[a[i+k][j+l]]=1;
                    }
                }
            }
        }
        cout << "Case #" << tt+1 << ": "  << (flag?"No":"Yes") << '\n';
    }
    return 0;
}