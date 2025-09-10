#include<bits/stdc++.h>
using namespace std;

int arr[104][104],n,L,ret;
int visited[104];
vector<int>v[204];

bool check(vector<int>&path){
	memset(visited,0,sizeof(visited));
	
	for(int i=0;i<n-1;i++){
		if(abs(path[i]-path[i+1])>=2)return false;
		if(path[i]==path[i+1])continue;
		if(path[i]>path[i+1]){
			//lowwer
			if(i+L>=n)return false;//is there enough space
			
			int pivot=path[i+1];
			
			for(int j=i+1;j<=i+L;j++){
				if(path[j]!=pivot||visited[j]){
					return false;
				}
			}
			
			for(int j=i+1;j<=i+L;j++){
				visited[j]=1;
			}
		}else{
			if(i-L+1<0)return false;
			
			int pivot=path[i];
			
			for(int j=i;j>i-L;j--){
				if(path[j]!=pivot||visited[j]){
					return false;
				}
			}
			
			for(int j=i;j>i-L;j--)
			{
				visited[j]=1;
			}
		}
	}
	
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>L;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
			}
	}
	
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			v[row].push_back(arr[row][col]);
		}
	}
	
	for(int col=0;col<n;col++){
		for(int row=0;row<n;row++){
			v[col+n].push_back(arr[row][col]);
		}
	}
	
	for(int i=0;i<2*n;i++){
		if(check(v[i])){
			ret++;
		}
	}
	
	cout<<ret;
	return 0;
}