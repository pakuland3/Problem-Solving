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
    return 0;
}