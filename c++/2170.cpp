#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct line{
    int start,end;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<line> a(n);
    for(line &t:a) cin >> t.start >> t.end;
    sort(a.begin(),a.end(),[](line &l, line &r)->bool{
        return l.start<r.start;
    });
    int res=0;
    int start=a[0].start,end=a[0].end;
    for(int i=1;i<n;i++){
        if(a[i].start<=end) end=max(end,a[i].end);
        else{
            res+=end-start;
            start=a[i].start;
            end=a[i].end;
        }
    }
    res+=end-start;
    cout << res;
    return 0;
}