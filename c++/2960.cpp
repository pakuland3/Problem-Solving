#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool a[1001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    int cnt=0;
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(!a[j]){
                cnt++;
                if(cnt==k){
                    cout << j;
                    return 0;
                }
                a[j]=1;
            }
        }
    }
    return 0;
}