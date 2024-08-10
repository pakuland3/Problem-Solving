#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct pos{
    int x,y,cnt;
};

int dx[]={1,-1,0,0,-1,-1,1,1};
int dy[]={0,0,1,-1,-1,1,-1,1};
int n,m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    char a[200][200];
    unordered_map<string,int> um;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        for(int k=0;k<8;k++){
            int x=i;
            int y=j;
            string cur("tour");
            cur[0]=a[i][j];
            bool d=0; 
            for(int l=0;l<3;l++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(n<=nx || nx<0 || m<=ny || ny<0) break;
                cur[l+1]=a[nx][ny];
                x=nx;
                y=ny;
                if(l==2) d=1;
            }
            if(d){
                if(um.find(cur)!=um.end()) um[cur]++;
                else um[cur]=1;
            }
        }
    }
    vector<string> mbti={"ENFJ","ENFP","ENTJ","ENTP","ESFJ","ESFP","ESTJ","ESTP"};
    for(int i=0;i<8;i++){
        string m=mbti[i];
        m[0]='I';
        mbti.push_back(m);
    }
    int res=0;
    for(int i=0;i<16;i++) if(um.find(mbti[i])!=um.end()) res+=um[mbti[i]];
    cout << res;
    return 0;
}