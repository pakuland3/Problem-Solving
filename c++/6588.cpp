#include <bits/stdc++.h>
#define MAX 1000001
typedef long long ll;
using namespace std;

bool s[MAX];
vector<int> p;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    for(int i=2;i<MAX;i++){
        if(s[i]) continue;
        p.push_back(i);
        for(int j=2*i;j<MAX;j+=i) s[j]=1;
    }
    while(1){
        cin >> n;
        if(n==0) break;
        int idx=0,ans,nn=n/2;
        while(p[idx]<=nn){
            if(binary_search(p.begin(),p.end(),n-p[idx])){
                ans=p[idx];
                break;
            }
            idx++;
        }
        cout << n << " = " << ans << " + " << n-ans << '\n';
    }
    return 0;
}