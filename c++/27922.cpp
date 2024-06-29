#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    int a,b,c;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<p> q(n);
    for(auto &f:q) cin >> f.a >> f.b >> f.c;
    sort(q.begin(),q.end(),[](p &l, p&r)->bool{
        return l.a+l.b>r.a+r.b;
    });
    int sum=0;
    for(int i=0;i<k;i++) sum+=q[i].a+q[i].b;
    int ans=sum;
    sort(q.begin(),q.end(),[](p &l, p&r)->bool{
        return l.b+l.c>r.b+r.c;
    });
    sum=0;
    for(int i=0;i<k;i++) sum+=q[i].b+q[i].c;
    ans=max(ans,sum);
    sort(q.begin(),q.end(),[](p &l, p&r)->bool{
        return l.a+l.c>r.a+r.c;
    });
    sum=0;
    for(int i=0;i<k;i++) sum+=q[i].a+q[i].c;
    ans=max(ans,sum);
    cout << ans;
    return 0;
}