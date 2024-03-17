#include <bits/stdc++.h>
using namespace std;

void solve(){
    bool f[100]={0,};
    bool vis[100]={0,};
    char c;
    int n,s=0,mini=3,cnt,dx[]={-1,0,1},ans=0;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> c; arr[i]=c-'0';
        if(arr[i]<mini){s=i;mini=arr[i];}
    }
    for(int i=0;i<n;i++){
        cin >> c;
        if(c=='*'){
            f[i]=1;
            ans++;
            for(int j=0;j<3;j++){
                if(n<=i+dx[j] || i+dx[j]<0) continue;
                arr[i+dx[j]]--;
            }
            if(arr[i]<mini){s=i;mini=arr[i];}
        }
    }
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int now=q.front(); q.pop(); vis[now]=true;
        for(int i=0;i<arr[now];i++){
            for(int j=0;j<3;j++){
                if(n<=now+dx[j] || now+dx[j]<0) continue;
                if(!f[now+dx[j]]){
                    bool b=true;
                    for(int l=0;l<3;l++){
                        if(n<=now+dx[j]+dx[l] || now+dx[j]+dx[l]<0) continue;
                        if(arr[now+dx[j]+dx[l]]==0) b=false;
                    }
                    if(b){
                        ans++;
                        f[now+dx[j]]=1;
                        for(int k=0;k<3;k++){
                            if(n<=now+dx[j]+dx[k] || now+dx[j]+dx[k]<0) continue;
                            arr[now+dx[j]+dx[k]]--;
                        }
                        break;
                    }
                }
            }
        }
        for(int i=0;i<3;i++){
            if(n<=now+dx[i] || now+dx[i]<0) continue;
            if(!vis[now+dx[i]]) q.push(now+dx[i]);
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

#include <iostream>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int sum=0,n,inn;
        char c[101];
        cin >> n;
        for(int i=0;i<n;i++){scanf("%1d",&inn);sum+=inn;}
        scanf("%s",c);
        cout << (sum+2)/3 << '\n';
    }
    return 0;
}