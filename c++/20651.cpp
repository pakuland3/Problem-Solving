#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int p[100];
    int res=0;
    for(int i=0;i<n;i++){
        cin >> p[i];
        if(i!=0) p[i]+=p[i-1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int sum=j!=0?p[i]-p[j-1]:p[i];
            if(sum%(i-j+1)!=0) continue;
            sum/=i-j+1;
            for(int k=j;k<=i;k++){
                int cur=k!=0?p[k]-p[k-1]:p[k];
                if(cur==sum){
                    res++;
                    break;
                }
            }
        }
    }
    cout << res;
    return 0;
}