#include<bits/stdc++.h>
using namespace std;

int j_visited[1004][1004],f_visited[1004][1004];
char arr[1004][1004];

pair<int,int> ji;
queue<pair<int,int>>fires;
vector<pair<int,int>>v;

int r,c,ret;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int main(){
	cin>>r>>c;
	vector<pair<int,int>> v;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf(" %c",&arr[i][j]);
			if(arr[i][j]=='J'){
				ji={i,j};
				j_visited[i][j]=1;
				
				if(i==0||j==0||i==r-1||j==c-1)
					v.push_back(ji);
			}
			else if(arr[i][j]=='F'){
				fires.push({i,j});
				f_visited[i][j]=1;
			}else if((arr[i][j]=='.')&&(i==0||j==0||i==r-1||j==c-1)){
				v.push_back({i,j});
			}
		}
	}
	

	while(fires.size()){
		int y,x;
		
		tie(y,x)=fires.front();fires.pop();
		
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(nx<0||ny<0||nx>=c||ny>=r)continue;
			if(arr[ny][nx]=='#')continue;
			if(f_visited[ny][nx]!=0)continue;
			
			fires.push({ny,nx});
			f_visited[ny][nx]=f_visited[y][x]+1;
		}
	}
	
	queue<pair<int,int>>qj;
	qj.push(ji);	
	
	while(qj.size()){
		int y,x;
		
		tie(y,x)=qj.front();qj.pop();
		
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(nx<0||ny<0||nx>=c||ny>=r)continue;
			if(arr[ny][nx]=='#')continue;
			if(j_visited[ny][nx])continue;
			if(j_visited[y][x]+1<f_visited[ny][nx]||f_visited[ny][nx]==0){
				qj.push({ny,nx});
				j_visited[ny][nx]=j_visited[y][x]+1;
			}
		}
	}
	/*
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout<<f_visited[i][j];
		cout<<'\n';
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout<<j_visited[i][j];
		cout<<'\n';
	}
	*/
	int ret=INT_MAX;
	for(auto exit:v){
		if(j_visited[exit.first][exit.second])ret=min(ret,j_visited[exit.first][exit.second]);
	}
	
	if(ret!=INT_MAX)cout<<ret;
	else cout<<"IMPOSSIBLE";
	return 0;
}