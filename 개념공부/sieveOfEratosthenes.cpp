#include<bits/stdc++.h>
using namespace std;

const int max_size=40;
bool che[max_size+1];

int main(){
	
	for(int i=2;i<=max_size;i++){
		if(che[i])continue;
		
		for(int j=i*2;j<=max_size;j+=i)
		{
			che[j]=true;
		}
	}	
	
	for(int i=2;i<=max_size;i++){
		if(!che[i])
			cout<<i<<" ";
	}
	return 0;
}