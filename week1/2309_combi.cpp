#include<bits/stdc++.h>
using namespace std;

int n=9,r=7;
int arr[9];
vector<int> b;

void print(vector<int>&b){
	for(auto item:b)
	{
		cout<<item<<'\n';
	}
}

void combi(int start,vector<int>&b){
	if(b.size()==r&&accumulate(b.begin(),b.end(),0)==100){
		print(b);
		return;
	}
	
	for(int i=start+1;i<n;i++){
		b.push_back(arr[i]);
		combi(i,b);
		b.pop_back();
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	for(int i=0;i<9;i++){
		cin>>arr[i];
	}
	sort(arr,arr+9);
	combi(-1,b);
}