#include <bits/stdc++.h>
using namespace std;

int n,q,a,b;
int cnt[100001]={0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; n--;
    while(n--){
        cin >> a >> b;
        cnt[a]++; cnt[b]++;
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(a==1){
            if(cnt[b]>1) cout << "yes";
            else cout << "no";
        }
        else cout << "yes";
        cout << '\n';
    }
    return 0;
}