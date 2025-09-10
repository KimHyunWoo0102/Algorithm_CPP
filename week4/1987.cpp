#include<bits/stdc++.h>
using namespace std;

int r,c,ret,ny,nx;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
char arr[21][21];

void go(int y,int x,int num,int cnt){
	ret=max(cnt,ret);
	
	for(int i=0;i<4;i++){
		ny=y+dy[i];
		nx=x+dx[i];
		
		if(ny<0||nx<0||nx>=c||ny>=r)continue;
		
		int _next=(1<<(int)(arr[ny][nx]-'A'));
		if((num&_next)==0)go(ny,nx,num|_next,cnt+1);
	}
	return;
}

int main(){
	cin>>r>>c;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}	
	
	go(0,0,1<<(int)(arr[0][0]-'A'),1);
	
	cout<<ret;
}