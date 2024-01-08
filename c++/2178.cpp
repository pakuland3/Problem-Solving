#include <bits/stdc++.h>
using namespace std;

bool graph[10001][101];
int N;
int M;
int tiles=0;
bool done=false;
bool flag=false;

void bfs(){
	queue<pair<int, int>> q;
	tiles++;
	q.push(make_pair(0,0));
	while(not q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		graph[x][y]=false;
		q.pop();
		if(x<N-1){
			if(graph[x+1][y]){
				q.push(make_pair(x+1,y));
				if(x+1==N-1 || y==M-1){
					done=true;
				}
				flag=true;
			}
		}
		if(y<M-1){
			q.push(make_pair(x,y+1));
			if(x==N-1 || y+1==M-1){
				done=true;
			}
			flag=true;
		}
		if()
		if(done){
			break;
		}
		if(flag){
			tiles++;
			flag=false;
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&graph[i][j]);
		}
	}
	
	bfs();
	cout << tiles;
}
