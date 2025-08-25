#include<bits/stdc++.h>
using namespace std;

char arr[104][104];
int visited[104][104];
int h,w;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>h>>w;
	
	memset(visited,-1,sizeof(visited));
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='c')visited[i][j]=0;
		}
	}
	
	
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w-1;j++){
			if(visited[i][j]==0){
				while(j<w-1&&visited[i][j+1]==-1){
					visited[i][j+1]=visited[i][j]+1;
					j++;	
				}
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<visited[i][j]<<' ';
		}
		cout<<'\n';
	}
	
	
	return 0;
}
