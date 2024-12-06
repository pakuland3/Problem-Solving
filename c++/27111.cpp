#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,res;
bool r[200001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        if(!r[a]^b) res++;
        r[a]=b;
    }
    for(int i=1;i<200001;i++) res+=r[i];
    cout << res;
    return 0;
}