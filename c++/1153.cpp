#include <bits/stdc++.h>
#define MAX 1000001
typedef long long ll;
using namespace std;

vector<int> p;
bool s[MAX];

int solve(int a){
    int idx=0;
    while(p[idx]<=a/2){
        if(binary_search(p.begin(),p.end(),a-p[idx])) return p[idx];
        idx++;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i=2;i<MAX;i++){
        if(s[i]) continue;
        p.push_back(i);
        for(int j=2*i;j<MAX;j+=i) s[j]=1;
    }
    int n;
    cin >> n;
    if(n<9){
        if(n==8) cout << "2 2 2 2";
        else cout << -1;
        return 0;
    }
    int a,b,c,d;
    if(n%2){
        cout << "2 3 "; n-=5;
        a=solve(n);
        cout << a << ' ' << n-a;
    }
    else{
        a=n/2-(n/2)%2;
        b=n/2+(n/2)%2;
        c=solve(a);
        d=solve(b);
        cout << c << ' ' << a-c << ' ' << d << ' ' << b-d;
    }
    return 0;
}