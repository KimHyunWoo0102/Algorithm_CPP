#include<bits/stdc++.h>
using namespace std;

int cnt,n;
vector<int> adj[56];

int root;

void go(int root){
	int child=0;
	cout<<root<<"\n";
	for(auto it:adj[root]){
		if(it==n)continue;
		go(it);
		child++;
	}
	
	if(child==0){
		cout<<root<<" has no child\n";
		cnt++;
		return ;
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	int parent;
	for(int i=0;i<n;i++){
		cin>>parent;
		
		if(parent==-1){
			root=i;
		}else {
			adj[parent].push_back(i);
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<"parent : "<<i<<" child : ";
		for(auto child:adj[i])
			cout<<child<<" ";
		cout<<'\n';
	}
	cin>>n;
	if(n!=root){
		go(root);
	}
	cout<<cnt;
	return 0;
}
