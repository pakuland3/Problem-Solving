#include <bits/stdc++.h>
using namespace std;

int lect[100000];
int n,m;
int mini=0;
int maxi=0;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> lect[i];
        maxi+=lect[i];
        mini=max(mini,lect[i]);
    }
    int s=mini;
    int e=maxi;
    while(s<=e){
        int mid=(s+e)/2;
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(sum+lect[i]>mid){
                cnt++;
                sum=lect[i];
            }
            else{
                sum+=lect[i];
            }
        }
        if(sum>0) cnt++;
        if(cnt>m){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout << s;
}