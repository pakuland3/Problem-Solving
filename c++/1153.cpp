#include <bits/stdc++.h>
#define MAX 1000001
typedef long long ll;
using namespace std;

vector<int> p;
bool s[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i=2;i<MAX;i++){
        if(s[i]) continue;
        p.push_back(i);
        for(int j=2*i;j<MAX;j+=i) s[j]=1;
    }
    int n;
    cin >> n;
    if(n%2){
        cout << -1;
        return 0;
    }
    int a=n/2-(n/2)%2;
    int b=n/2+(n/2)%2;
    if(a<4 || b<4){
        cout << -1;
        return 0;
    }
    int idx=0;
    int ans1,ans2;
    while(p[idx]<=a/2){
        if(binary_search(p.begin(),p.end(),a-p[idx])) ans1=p[idx];
        idx++;
    }
    idx=0;
    while(p[idx]<=b/2){
        if(binary_search(p.begin(),p.end(),b-p[idx])) ans2=p[idx];
        idx++;
    }
    cout << ans1 << ' ' << a-ans1 << ' ' << ans2 << ' ' << b-ans2;
    return 0;
}