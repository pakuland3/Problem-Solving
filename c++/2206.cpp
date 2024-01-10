#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visited[1001][1001];
int N;
int M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool ifbreak=false;
bool breakable=false;
bool directgo=false;

void bfs(){
	queue<pair<int, int>> q;
	visited[0][0]=true;
	q.push(make_pair(0,0));
	graph[0][0]=1;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		bool flag=0;
		
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(0<=nx && nx<N && 0<=ny && ny<M){
				if(graph[nx][ny]==0 && !visited[nx][ny]){
					q.push(make_pair(nx, ny));
					visited[nx][ny]=true;
					graph[nx][ny]=graph[x][y]+1;
					flag=true;
				}
				else if(graph[nx][ny]==1 && !visited[nx][ny] && !ifbreak){
					if(nx==N-2){
						if(ny==M-1){
							directgo=true;
						}
					}
					else if(nx==N-1){
						if(ny==M-2){
							directgo=true;
						}
					}
					if(directgo){
						q.push(make_pair(nx,ny));
						visited[nx][ny]=true;
						graph[nx][ny]=graph[x][y]+1;
						ifbreak=true;
						directgo=false;
					}
				}
			}
		}
		
		if(!flag && !ifbreak){
			for(int i=0;i<4;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				
				if(0<=nx && nx<N && 0<=ny && ny<M && q.size()==0){
					if(graph[nx][ny]==1 && !visited[nx][ny]){
						q.push(make_pair(nx,ny));
						visited[nx][ny]=true;
						graph[nx][ny]=graph[x][y]+1;
						breakable=true;
					}
				}
			}
			if(breakable){
				ifbreak=true;
			}
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d", &graph[i][j]);
		}
	}
	bfs();
	if(graph[N-1][M-1]!=0){
		cout << graph[N-1][M-1];
	}
	else{
		cout << -1;
	}
//	for(int i=0;i<N;i++){
//		for(int j=0;j<M;j++){
//			cout << graph[i][j] << ' ';
//		}
//		cout << '\n';
//	}
}
