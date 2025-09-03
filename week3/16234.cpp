#include<bits/stdc++.h>
using namespace std;

int n,l,r;
int arr[54][54],visited[54][54];

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

bool can_go(int y,int x){
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||nx<0||nx>=n||ny>=n)continue;
		int diff=abs(arr[ny][nx]-arr[y][x]);
		if(l<=diff&&diff<=r)return true;
	}
	
	return false;
}

void bfs(int y,int x){
	visited[y][x]=1;
	queue<pair<int,int>>q;
	vector<pair<int,int>>v;
	q.push({y,x});
	v.push_back({y,x});
	
	while(q.size()){
		tie(y,x)=q.front();q.pop();
		
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(nx<0||ny<0||nx>=n||ny>=n)continue;
			if(visited[ny][nx])continue;
			int dist=abs(arr[ny][nx]-arr[y][x]);
			
			if(l<=dist&&dist<=r){
				q.push({ny,nx});
				visited[ny][nx]=1;
				v.push_back({ny,nx});
			}
		}
	}

	int sum=0;
	for(auto it:v){
		sum+=arr[it.first][it.second];
	}
	
	sum/=v.size();
	
	for(auto it:v){
		arr[it.first][it.second]=sum;
	}
}

int main(){
	cin>>n>>l>>r;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	
	int cnt=-1;
	bool is_run=true;

	/*
	bfs(0,0);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<arr[i][j];
		cout<<'\n';
	}*/
	while(is_run){
		is_run=false;
		memset(visited,0,sizeof(visited));
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(can_go(i,j)&&!visited[i][j]){

					is_run=true;
					bfs(i,j);
				}
			}
		}	
		
		cnt++;
	}
	
	cout<<cnt;
	return 0;
}