#include<bits/stdc++.h>
using namespace std;
#define y1 jjskjk

char arr[1504][1504];
int visited_swan[1504][1504];

int r,c;
queue<pair<int,int>> w,swan;
vector<pair<int,int>> swan_pos;

int dy[]={0,1,0,-1},dx[]={-1,0,1,0};

void print_water(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout<<arr[i][j];
		cout<<'\n';
	}
}

void print(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout<<visited_swan[i][j];
		cout<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
	cin>>r>>c;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]=='L'){
				swan_pos.push_back({i,j});
				w.push({i,j});
			}
			if(arr[i][j]=='.'){
				w.push({i,j});
			}
		}
	}
	int cnt=0;
	visited_swan[swan_pos[0].first][swan_pos[0].second]=1;
	swan.push(swan_pos[0]);
	
	while(true){
		queue<pair<int,int>> swan_next;
		while(swan.size()){
			int y,x;
			tie(y,x)=swan.front();swan.pop();		
			
			for(int i=0;i<4;i++){
				int ny=y+dy[i];
				int nx=x+dx[i];
				
				if(ny<0||nx<0||nx>=c||ny>=r)continue;
				if(visited_swan[ny][nx])continue;
				if(arr[ny][nx]=='.'){
					swan.push({ny,nx});
					visited_swan[ny][nx]=1;
				}else {
					swan_next.push({ny,nx});
					visited_swan[ny][nx]=1;
				}
				if(ny==swan_pos[1].first&&nx==swan_pos[1].second){
					cout<<cnt;
					return 0;
				}
			}
		}
		
		swan=swan_next;
		queue<pair<int,int>> w_next;
		while(w.size()){
			int y,x;
			tie(y,x)=w.front();w.pop();
			
			for(int i=0;i<4;i++){
				int ny=y+dy[i];
				int nx=x+dx[i];
				
				if(ny<0||nx<0||nx>=c||ny>=r)continue;

				if(arr[ny][nx]=='X'){
					w_next.push({ny,nx});
					arr[ny][nx]='.';
				}
			}
		}
		cnt++;
		w=w_next;
	}
	
	cout<<cnt;
	return 0;
}