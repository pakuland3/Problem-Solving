#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[1001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k,n;
    cin >> k >> n;
    int maxi=1;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        a[t]++;
        if(a[t]>a[maxi]) maxi=t;
    }
    int flag;
    int cnt;
    char sign[]={'-','+'};
    int add[]={-1,1};
    for(int l=0;l<2;l++){
        for(int i=1;i<=k;i++){
            flag=1;
            a[i]+=add[l];
            if(a[i]<0){
                a[i]=0;
                continue;
            }
            cnt=a[1];
            for(int j=2;j<=k;j++) if(a[j]!=cnt) flag=0;
            a[i]-=add[l];
            if(flag){
                cout << sign[l] << i;
                return 0;
            }
        }
    }
    for(int i=1;i<=k;i++){
        flag=1;
        a[i]++;
        a[maxi]--;
        cnt=a[1];
        for(int j=1;j<=k;j++) if(a[j]!=cnt) flag=0;
        a[i]--;
        a[maxi]++;
        if(flag){
            cout << '-' << maxi << ' ' << '+' << i;
            return 0;
        }
    }
    cout << '*';
    return 0;
}