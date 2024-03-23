#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> lines;
vector<int> arr;
pair<int, int> tmp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; vector<int> ind(n);
    for(int i=0;i<n;i++){
        cin >> tmp.first >> tmp.second; lines.push_back(tmp);
    }
    sort(lines.begin(),lines.end(),[](pair<int, int> l, pair<int, int> r)->bool{
        return l.first<r.first;
    });
    arr.push_back(lines[0].second); ind[0]=0;
    for(int i=1;i<n;i++){
        if(lines[i].second>arr.back()){arr.push_back(lines[i].second);ind[i]=arr.size()-1;}
        else{
            auto it=lower_bound(arr.begin(),arr.end(),lines[i].second);
            *it=lines[i].second;
            ind[i]=it-arr.begin();
        }
    }
    int ans_ind=arr.size()-1; int cnt=0;
    for(int i=0;i<n;i++){
        if(ans_ind-cnt==ind[n-i-1]){
            arr[ans_ind-cnt]=lines[n-i-1].first; cnt++;
            if(cnt>arr.size()) break;
        }
    }
    cout << n-arr.size() << '\n';
    int s=0;
    for(int i=0;i<n;i++){
        if(lines[i].first!=arr[s]) cout << lines[i].first << '\n';
        else if(s<arr.size()-1) s++;
    }
    return 0;
}