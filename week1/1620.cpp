#include<bits/stdc++.h>
using namespace std;

vector<string> s;
map<string,int> m;

int n,k,c;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>k;
	
	string tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		s.push_back(tmp);
		m[tmp]=i;
	}	
	
	for(int i=0;i<k;i++)
	{
		cin>>tmp;
		
		if(isdigit(tmp[0])){
			cout<<s[stoi(tmp.c_str())-1]<<'\n';
		}else{
			cout<<m.at(tmp)<<'\n';
		}
	}
	return 0;
}