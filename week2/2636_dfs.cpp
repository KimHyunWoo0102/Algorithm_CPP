#include<bits/stdc++.h>
using namespace std;

int arr[105][105],visited[104][104];
vector<pair<int,int>>v;

int n,m;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void dfs(int y,int x){
	visited[y][x]=1;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||ny>=n||nx<0||nx>=m)continue;
		if(visited[ny][nx]==1)continue;
		if(arr[ny][nx]==0)dfs(ny,nx);
		else if(arr[ny][nx]==1){
			visited[ny][nx]=1;
			v.push_back({ny,nx});
		}
	}	
	
}
int ret,cnt;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	}	
	
	while(true){
		memset(visited,0,sizeof(visited));
		dfs(0,0);
		if(!v.size())break;
		ret=v.size();
		
		for(auto&melt:v){
			arr[melt.first][melt.second]=0;
		}
		v.clear();
		cnt++;
	}
	
	cout<<cnt<<'\n'<<ret;
	return 0;
}