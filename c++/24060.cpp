#include <bits/stdc++.h>
using namespace std;

int n;
int k;
int cnt=0;
int arr[500000];
int tmp[500000];

void lmerge(int p, int q, int r){
    int i=p; int j=q+1; int t=0;
    while(i<=q && j<=r){
        if(arr[i]<=arr[j]) tmp[t++]=arr[i++];
        else tmp[t++]=arr[j++];
    }
    while(i<=q) tmp[t++]=arr[i++];
    while(j<=r) tmp[t++]=arr[j++];
    i=p; t=0;
    while(i<=r){
        arr[i++]=tmp[t++];
        cnt++;
        if(cnt==k) cout << tmp[t-1];
    }
}

void lmerge_sort(int p, int r){
    if(p<r){
        int q=(p+r)/2;
        lmerge_sort(p,q);
        lmerge_sort(q+1,r);
        lmerge(p,q,r);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    lmerge_sort(0,n-1);
    if(cnt<k) cout << -1;
}