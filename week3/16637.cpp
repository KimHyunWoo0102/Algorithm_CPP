#include<bits/stdc++.h>
using namespace std;

int n;

vector<int>v1,v2,b;
char arr[40];

void go(int start,int len){
	if(b.size()==len*2){
		eval();
		return;
	}
	
	for(int i=start+1;i<v1.size();i++){
		
	}
}
int main(){
	cin>>n;
		
	for(int i=1;i<2*n;i+=2)
		cin>>arr[i];
	
	for(int i=0;i<=2*n;i+=4){
		v1.push_back(i);
	}
	
	for(int i=2;i<=2*n;i+=4){
		v2.push_back(i);
	}
	
	for(int i=0;i<n/2;i++){
		b.clear();
		go(-1,i);
	}
	
	return 0;
}
