#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int l,k,c,cut,ans,idx=2;
int x[10003];

bool solve(int mid){
    int cnt=0;
    int len=0;
    for(int i=idx-2;i>-1;i--){
        if(x[i+1]-x[i]>mid) return 0;
        if(len>0){
            if(len+x[i+1]-x[i]<mid) len+=x[i+1]-x[i];
            else{
                if(len+x[i+1]-x[i]==mid){
                    len=0;
                    if(i!=0){
                        cut=x[i];
                        cnt++;
                    }
                }
                else{
                    len=x[i+1]-x[i];
                    cut=x[i+1];
                    cnt++;
                }
            }
        }
        else len=x[i+1]-x[i];
    }
    if(cnt<c) cut=x[1];
    if(cnt>c) return 0;
    ans=cut;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> l >> k >> c;
    for(int i=1;i<=k;i++) cin >> x[i];
    sort(x+1,x+k+1); for(int i=2;i<=k;i++) if(x[i]!=x[i-1]) x[idx++]=x[i];
    x[idx++]=l;
    int s=1,e=l;
    while(s<=e){
        int mid=(s+e)/2;
        if(solve(mid)) e=mid-1;
        else s=mid+1;
    }
    cout << s << ' ' << ans;
    return 0;
}