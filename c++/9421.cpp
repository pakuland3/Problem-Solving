#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int sieve[1000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int l=sqrt(1000000);
    for(int i=2;i<=l;i++) for(int j=i*i;j<=1000000;j+=i) sieve[j]=1;
    unordered_map<int,int> m;
    for(int i=2;i<=n;i++){
        unordered_set<int> s;
        auto sum=[&](int tt){
            int s=0;
            while(tt){
                int t=(tt%10);
                s+=t*t;
                tt/=10;
            }
            return s;
        };
        if(!sieve[i]){
            if(m.find(i)!=m.end()){
                if(m[i]) cout << i << '\n';
                continue;
            }
            int t=i;
            int flag=0;
            while(s.find(t)==s.end()){
                if(t==1 || (m.find(t)!=m.end() && m[t])){
                    flag=1;
                    break;
                }
                s.insert(t);
                t=sum(t);
            }
            for(auto it=s.begin();it!=s.end();it++) m[*it]=flag;
            if(flag) cout << i << '\n';
        }
    }
    return 0;
}