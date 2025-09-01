#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	
	cin>>n;
	
	int cnt=0;
	int i=666;
	char nums[1000];
	while(cnt!=n){
		//cout<<"cnt = "<<cnt<<" num = "<<i<<'\n';
		if(to_string(i).find("666")!=string::npos)cnt++;
		i++;	
	}
	
	cout<<i-1;
	return 0;
}