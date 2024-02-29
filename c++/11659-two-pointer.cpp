#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,sum=0,m; cin >> n >> m;
    vector<int> arr(n);
    vector<pair<pair<int, int>, pair<int, int>>> tasks(m);
    vector<pair<int, int>> ans;
    for(int i=0;i<n;i++){cin >> arr[i];sum+=arr[i];} int s=0,e=n-1;
    for(int i=0;i<m;i++){cin >> tasks[i].second.first >> tasks[i].second.second;tasks[i].first.first=tasks[i].second.second-tasks[i].second.first; tasks[i].first.second=i;}
    sort(tasks.begin(),tasks.end(),[](pair<pair<int, int>, pair<int, int>> l, pair<pair<int, int>, pair<int, int>> r)->bool{
        return l.first.first>r.first.first;
    });
    for(int i=0;i<m;i++){
        int l=tasks[i].second.first-1;
        int r=tasks[i].second.second-1;
        while(s!=l || e!=r){
            if(s>l) sum+=arr[--s];
            else if(s<l) sum-=arr[s++];
            if(e>r) sum-=arr[e--];
            else if(e<r) sum+=arr[++e];
        }
        ans.push_back({tasks[i].first.second,sum});
    }
    sort(ans.begin(),ans.end(),[](pair<int, int> l, pair<int, int> r)->bool{
        return l.first<r.first;
    });
    for(pair<int, int> p:ans) cout << p.second << '\n';
    return 0;
}