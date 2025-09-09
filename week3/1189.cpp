#include<bits/stdc++.h>
using namespace std;

#define y1 sdkawlkdl
int r,c,k,ret;
char arr[7][7];
int visited[7][7];
int y1,x1;
int dy[]={0,1,0,-1},dx[]={-1,0,1,0};

void print(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout<<visited[i][j];
		cout<<'\n';
	}
	cout<<'\n';
}
void dfs(int y,int x,int cnt){
	if(y==0&&x==c-1){
		if(cnt==k){
			ret++;
		}
		return;
	}
	
	if(cnt>=k)return;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||nx<0||nx>=c||ny>=r)continue;
		if(visited[ny][nx])continue;
		if(arr[ny][nx]!='.')continue;
		
		visited[ny][nx]=1;
		dfs(ny,nx,cnt+1);
		visited[ny][nx]=0;
	}
}
int main(){
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
	cin>>r>>c>>k;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cin>>arr[i][j];
	}
	
	visited[r-1][0]=1;
	
	dfs(r-1,0,1);
	
	cout<<ret;
	return 0;
}