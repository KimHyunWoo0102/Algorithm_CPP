#include<bits/stdc++.h>
using namespace std;

vector<int>v={1,2,3,4,5};
int n=5,r=4;

void print(vector<int>& b){
	for(auto item : b)cout<<item<<" ";
	cout<<'\n';
}

void combi(int start,vector<int>&b){
	if(b.size()==r) 
	{
		print(b);		
		return;
	}
	
	for(int i=start+1;i<n;i++){
		b.push_back(v[i]);
		combi(i,b);
		b.pop_back(); //restoration
	}
	return;
}
int main(){
	vector<int> b;
	
	combi(-1,b);
	return 0;
}