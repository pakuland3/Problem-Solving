#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int A[100][100],B[100][100],ans[100][100]={0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];
    cin >> m >> k;
    for(int i=0;i<m;i++) for(int j=0;j<k;j++) cin >> B[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<k;j++) for(int l=0;l<m;l++) ans[i][j]+=A[i][l]*B[l][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}