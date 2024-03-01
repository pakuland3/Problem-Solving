#include <bits/stdc++.h>
using namespace std;

int n;
int ans=3000;
int sc[20][20]; //0~n-1

void dfs(vector<int> arr, int ind){
    if(arr.size()==n/2){
        int sumA=0;
        int sumB=0;
        for(int i=0;i<n/2;i++) for(int j=i+1;j<n/2;j++) sumA+=sc[arr[i]][arr[j]]+sc[arr[j]][arr[i]];
        vector<int> tmp; for(int i=0;i<n;i++){
            if(!binary_search(arr.begin(),arr.end(),i)) tmp.push_back(i);
        }
        for(int i=0;i<n/2;i++) for(int j=i+1;j<n/2;j++) sumB+=sc[tmp[i]][tmp[j]]+sc[tmp[j]][tmp[i]];
        ans=min(ans,abs(sumA-sumB));
        return;
    }
    vector<int> tmp(arr);
    for(int i=ind+1;i<n;i++){
        tmp.push_back(i);
        dfs(tmp,i);
        tmp.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> sc[i][j];
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(i);
        dfs(v,i);
        v.pop_back();
    }
    cout << ans;
    return 0;
}