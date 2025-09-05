#include<bits/stdc++.h>
using namespace std;

int r,c;
char arr[24][24];
int visited[26];
int ret;

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

bool can_go(int y,int x){
	bool f=false;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||nx<0||ny>=r||nx>=c)continue;
		if(visited[arr[ny][nx]-'A'])continue;
		f=true;	
	}
	
	return f;
}
void go(int y,int x,int cnt){
	if(!can_go(y,x)){
		ret=max(cnt,ret);
	}
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||nx<0||ny>=r||nx>=c)continue;
		if(visited[arr[ny][nx]-'A'])continue;
		visited[arr[ny][nx]-'A']=1;
		go(ny,nx,cnt+1);
		visited[arr[ny][nx]-'A']=0;
	}
	
}
int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>r>>c;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf(" %c",&arr[i][j]);		
		}
	}
	
	visited[arr[0][0]-'A']=1;
	go(0,0,0);
	cout<<ret+1;
	return 0;
}