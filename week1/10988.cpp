#include<bits/stdc++.h>
using namespace std;

int main(){
	string str,rstr;
	cin>>str;
	rstr=str;
	reverse(str.begin(),str.end());
	
	cout<<(rstr==str)<<endl;
	return 0;
}