#include<bits/stdc++.h>
using namespace std;

#define y1 asdkl23
char arr[304][304];
int visited[304][304];
int x1,x2,y1,y2,x,y;
int n,m;
int dy[]={0,1,0,-1},dx[]={-1,0,1,0};
vector<pair<int,int>>v;

void dfs(int y,int x){
	visited[y][x]=1;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<=0||nx<=0||nx>m||ny>n)continue;
		if(visited[ny][nx])continue;
		if(arr[ny][nx]=='1'||arr[ny][nx]=='#'){
			visited[ny][nx]=1;
			v.push_back({ny,nx});
		}else if(arr[ny][nx]=='0'){
			visited[ny][nx]=1;
			dfs(ny,nx);
		}
	}
}
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<arr[i][j];
		cout<<'\n';
	}
}
int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	cin>>y1>>x1>>y2>>x2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			scanf(" %c",&arr[i][j]);
	}
	
	
	int cnt=0;
	
	while(true){
		memset(visited,0,sizeof(visited));
		
		dfs(y1,x1);
		cnt++;
		
		
		for(auto pos:v){
			arr[pos.first][pos.second]='0';
		}
		if(arr[y2][x2]=='0')break;
		v.clear();
	}

	cout<<cnt;
	return 0;
}