#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct land{
    int h,idx;
    bool operator<(land &l){
        return h<l.h;
    };
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<land> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].h;
        a[i].idx=i;
    }
    sort(a.begin(),a.end());
    int cur=1;
    int ans=1;
    vector<bool> done(n,1);
    for(int i=0;i<n;i++){
        int ix=a[i].idx;
        done[ix]=0;
        bool l=(ix>0 && done[ix-1]);
        bool r=(ix<n-1 && done[ix+1]);
        if(l && r) cur++;
        else if(!l && !r) cur--;
        if(i==n-1 || a[i]<a[i+1]) ans=max(ans,cur);

    }
    cout << ans;
    return 0;
}