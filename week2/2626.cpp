#include<bits/stdc++.h>
using namespace std;

int n,m;

int arr[104][104],visited[104][104];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int y,x;
queue<pair<int,int>>q;
int prev_cnt,cnt;

void dfs(int y,int x){
	visited[y][x]=1;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||nx<0||nx>=m||ny>=n)continue;
		if(visited[ny][nx]==1)continue;
	    if(arr[ny][nx]==0)dfs(ny,nx);
	    else {
	    	q.push({ny,nx});
	    	visited[ny][nx]=1;
		}
	}	
}

void print_arr(){
	cout<<'\n';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<arr[i][j]<<' ';
		cout<<'\n';
	}
}

void print_visited(){
	cout<<'\n';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<visited[i][j]<<' ';
		cout<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}	
	
	while(true){
		memset(visited,0,sizeof(visited));
		dfs(0,0);
		
		if(!q.size())break;
		prev_cnt=q.size();
		while(q.size()){
			tie(y,x)=q.front();q.pop();
			arr[y][x]=0;
		}//ƒ°¡Ó ≥Ï¿Ã±‚
		cnt++; 
	}
	
	cout<<cnt<<'\n'<<prev_cnt;

	
	return 0;
}
