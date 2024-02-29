#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visited[1001][1001][2]; //simply stores shorstest path;
int N;                      //ind 0 = just go; ind 1 = crash wall;
int M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs(){
	queue<tuple<int, int, bool>> q; //bool ind 2 = state wall crashed
	q.push({0,0,0});
	
	while(!q.empty()){
		int x=get<0>(q.front());
		int y=get<1>(q.front());
		int crashed=get<2>(q.front());
		
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(0<=nx && nx<N && 0<=ny && ny<M){
				//no wall and no visit
				if(graph[nx][ny]==0 && visited[nx][ny][crashed]==0){
					visited[nx][ny][crashed]=visited[x][y][crashed]+1;
					q.push({nx,ny,crashed});
				}
				//wall and no visit, crash wall
				else if(graph[nx][ny]==1 && visited[nx][ny][crashed]==0){
					if(!crashed){
						visited[nx][ny][1]=visited[x][y][0]+1;
						q.push({nx,ny,1});
					}
				}
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
	visited[0][0][0]=1;
	bfs();
	if(visited[N-1][M-1][0]>0){
		if(visited[N-1][M-1][1]>0){
			cout << min(visited[N-1][M-1][1], visited[N-1][M-1][0]);
		}
		else{
			cout << visited[N-1][M-1][0];
		}
	}
	else{
		if(visited[N-1][M-1][1]>0){
			cout << visited[N-1][M-1][1];
		}
		else{
			cout << -1;
		}
	}
}