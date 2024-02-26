#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tc;
int n;
bool ans;

void copy_arr(char a[][6], char b[][6]){
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j]=b[i][j];
}

void check(char arr[][6]){
	bool b=true;
	for(pair<int, int> p:tc){
		int x=p.first;
		int y=p.second;
		for(int i=x-1;i>-1;i--){
			if(arr[i][y]=='O') break;
			else if(arr[i][y]=='S'){b=false;break;}
		}
		for(int i=x+1;i<n;i++){
			if(arr[i][y]=='O') break;
			else if(arr[i][y]=='S'){b=false;break;}
		}
        for(int i=y-1;i>-1;i--){
            if(arr[x][i]=='O') break;
            else if(arr[x][i]=='S'){b=false;break;}
        }
        for(int i=y+1;i<n;i++){
            if(arr[x][i]=='O') break;
            else if(arr[x][i]=='S'){b=false;break;}
        }
		if(!b) break;
	}
	if(b) ans=true;
}

void solve(int cnt, int indx, int indy, char arr[][6]){
	if(ans) return;
	if(cnt==3){check(arr);return;}
	char tmp[6][6]; copy_arr(tmp, arr);
    for(int i=indx;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==indx && j<=indy) continue;
            if(tmp[i][j]=='X'){
                tmp[i][j]='O';
                solve(cnt+1,i,j,tmp);
                tmp[i][j]='X';
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char arr[6][6];
	cin >> n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++){cin >> arr[i][j]; if(arr[i][j]=='T') tc.push_back({i,j});}
	solve(0,0,-1,arr);
    if(ans) cout << "YES";
    else cout << "NO";
	return 0;
}