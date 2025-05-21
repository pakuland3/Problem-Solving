#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

vector<pair<int,int>> a;
int res=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    a.resize(n);
    for(auto &p:a){
        int t;
        cin >> p.fi >> p.se >> t;
        p.se=10*p.se+t;
        if(p.se==30){
            cout << 0;
            return 0;
        }
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(i==j) continue;
            for(int k=1;k<10;k++){
                if(k==i || k==j) continue;
                int c[]={i,j,k};
                int f=1;
                for(auto &p:a){
                    int t[]={p.fi/100,(p.fi/10)%10,p.fi%10};
                    int cnt=0;
                    if(p.se/10==0){
                        for(int l=0;l<3;l++) cnt+=(c[l]==t[l]);
                        if(cnt){
                            f=0;
                            break;
                        }
                        for(int l=0;l<3;l++) for(int h=0;h<3;h++) cnt+=(c[l]==t[h]);
                        f=(cnt==p.se%10);
                    }
                    if(p.se/10){
                        int idx[]={-1,-1};
                        int it=0;
                        for(int l=0;l<3;l++){
                            if(c[l]==t[l]){
                                idx[it++]=l;
                                cnt++;
                            }
                        }
                        f=(cnt==p.se/10);
                        if(!f) break;
                        cnt=0;
                        for(int l=0;l<3;l++){
                            int cn=0;
                            for(int h=0;h<p.se/10;h++){
                                if(l==idx[h]){
                                    cn=1;
                                    break;
                                }
                            }
                            if(cn) continue;
                            for(int h=0;h<3;h++) cnt+=(c[l]==t[h]);
                        }
                        f=(cnt==p.se%10);
                    }
                    if(!f) break;
                }
                res+=f;
            }
        }
    }
    cout << res;
    return 0;
}