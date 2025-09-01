#include<bits/stdc++.h>
using namespace std;

int cnt,n;
vector<int> adj[56];

void go(int root){
	
	int child=0;
	for(auto it:adj[root]){
		if(it==n)continue;
		go(it);
		child++;
	}
	
	if(child==0){
		cnt++;
		return;
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	
	int root=0;
	
	for(int i=0;i<n;i++){
		int parent;
		cin>>parent;
		if(parent==-1)root=i;
		else{
			adj[parent].push_back(i);
		}
	}
	
	cin>>n;
	if(n!=root){
		go(root);
	}
	cout<<cnt;

	return 0;
}
