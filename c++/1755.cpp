#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct nm{
    int v;
    string s="";
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n;
    cin >> m >> n;
    string number[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector<nm> a(n-m+1);
    for(int i=0;m+i<=n;i++){
        a[i].v=m+i;
        if(a[i].v>9) a[i].s+=number[a[i].v/10]+' ';
        a[i].s+=number[a[i].v%10];
    }
    sort(a.begin(),a.end(),[](nm &b, nm &c) -> bool { return b.s<c.s; });
    for(int i=0;i<n-m+1;i++){
        cout << a[i].v << ' ';
        if(i%10==9) cout << '\n';
    }
    return 0;
}