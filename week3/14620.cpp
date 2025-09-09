#include<bits/stdc++.h>
using namespace std;

int n,g;
int arr[204][204],visited[204][204];
int dy[]={0,1,0,-1},dx[]={-1,0,1,0};
int max_flower=3;
int ret=INT_MAX;

bool can_flower(int y,int x){
    // 꽃의 중심점과 주변 4칸이 모두 유효한 범위에 있는지 확인
    if (y <= 0 || y >= n-1 || x <= 0 || x >= n-1) return false;
    
    // 꽃의 중심과 주변 4칸이 이미 방문되었는지 확인
    if (visited[y][x]) return false;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(visited[ny][nx]) return false;
    }
    return true;
}
void make_flower(int y,int x){
	visited[y][x]=1;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		visited[ny][nx]=1;
	}
}

int check(){
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(visited[i][j])
				sum+=arr[i][j];
	}
	return sum;
}
void delete_flower(int y,int x){
	visited[y][x]=0;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		visited[ny][nx]=0;
	}
}
void solve(int count,int starty,int startx){
	if(count==max_flower){
		ret=min(ret,check());
		return;
	}
	
	for(int i=starty;i<n;i++){
		for(int j=((starty==i)?startx:0);j<n;j++){
			if(can_flower(i,j)){
				make_flower(i,j);
				solve(count+1,i,j+1);
				delete_flower(i,j);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	solve(0,0,0);
	
	cout<<ret;
	return 0;
}