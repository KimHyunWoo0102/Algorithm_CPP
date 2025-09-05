#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[1040];
vector<int> v[15];
void search(int start,int end,int level){
	if(level>n)return;
	int mid=(start+end)/2;
	
	v[level].push_back(arr[mid]);
	search(start,mid-1,level+1);
	search(mid+1,end,level+1);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	
	k=pow(2,n)-1;
	
	for(int i=0;i<k;i++)
		cin>>arr[i];
		
	search(0,k,1);
	
	for(int i=1;i<=n;i++){
		for(auto it:v[i])
			cout<<it<<" ";
		cout<<'\n';
	}
	return 0;
}