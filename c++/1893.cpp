#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string a,w,s;
int idx[128];
int f[50001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> a >> w >> s;
        vector<int> sfts;
        for(int i=0;i<a.size();i++) idx[a[i]]=i;
        int j=0;
        for(int i=1;i<w.size();i++){
            while(j>0 && w[i]!=w[j]) j=f[j-1];
            if(w[i]==w[j]) f[i]=++j;
            else f[i]=0;
        }
        for(int c=0;c<a.size();c++){
            int cnt=0;
            j=0;
            for(int i=0;i<s.size();i++){
                char ch=a[(idx[s[i]]-c+a.size())%a.size()];
                while(j>0 && ch!=w[j]) j=f[j-1];
                if(ch==w[j]) j++;
                if(j==w.size()){
                    j=f[j-1];
                    cnt++;
                }
            }
            if(cnt==1) sfts.push_back(c);
        }
        sort(sfts.begin(),sfts.end());
        if(sfts.empty()){
            cout << "no solution\n";
            continue;
        }
        cout << (sfts.size()==1?"unique":"ambiguous") << ": ";
        for(int t:sfts) cout << t << ' ';
        cout << '\n';
    }
    return 0;
}