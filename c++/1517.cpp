#include <bits/stdc++.h>
#define SIZE 500001
typedef long long ll;
using namespace std;

int a[SIZE];
ll res=0;

void merge(int s, int mid, int e){
    int tmp[SIZE];
    int i=s,j=mid+1,k=s;
    while(i<=mid && j<=e){
        if(a[i]>a[j]){
            res+=(ll)(j-k);
            tmp[k++]=a[j++];
        }
        else tmp[k++]=a[i++];
    }
    while(i<=mid) tmp[k++]=a[i++];
    while(j<=e) tmp[k++]=a[j++];
    for(k=s;k<=e;k++) a[k]=tmp[k];
}

void merge_sort(int s, int e){
    if(s<e){
        int mid=(s+e)/2;
        merge_sort(s,mid);
        merge_sort(mid+1,e);
        merge(s,mid,e);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("in_out/output.out","w",stdout);
    // int k = 500000;
    // cout << k << '\n';
    // for (int i = k; i >= 1; --i) {
    //     cout << i << (i == 1 ? '\n' : ' ');
    // }
    // freopen("in_out/output.out","r",stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    merge_sort(0,n-1);
    cout << res;
    return 0;
}