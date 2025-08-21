#include<bits/stdc++.h>
using namespace std;

int n,m;

map<string,vector<string>> v;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string s1,s2;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		int ret=1;
		cin>>m;
		
		for(int j=0;j<m;j++){
			cin>>s1>>s2;
			
			v[s2].push_back(s1);
		}
		
		
		for(auto it : v){
			ret*=it.second.size()+1;
		}
		
		ret--;
		cout<<ret<<'\n';
		v.clear();
	}	
	
	return 0;
}