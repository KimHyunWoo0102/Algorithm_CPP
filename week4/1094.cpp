#include<bits/stdc++.h>
using namespace std;

int n=64,k,cnt;

int main(){
	cin>>k;
	
	for(int i=0;i<=6;i++){
		if(k&(1<<i))
		cnt++;
	}
	
	cout<<cnt;
	return 0;
}