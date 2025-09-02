#include<bits/stdc++.h>
using namespace std;

using ll=long long;
stack<ll> s;

ll n;
ll arr[1000004],nge[1000004];

int main(){
	cin>>n;
	
	memset(nge,-1,sizeof(nge));
	for(int i=0;i<n;i++){
		cin>>arr[i];		
	}	
	
	for(int i=0;i<n;i++){
	
		while(s.size()&&arr[i]>arr[s.top()]){
				//cout<<"arr[i] "<<arr[i]<<" s.top().second "<<s.top().second<<'\n';
			nge[s.top()]=arr[i];
			s.pop();
		}		
			
			s.push(i);
	}
	
	for(int i=0;i<n;i++)
		cout<<nge[i]<<" ";
	return 0;
}