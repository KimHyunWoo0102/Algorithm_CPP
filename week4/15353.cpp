#include<bits/stdc++.h>
using namespace std;

string str1,str2,ret;

int main(){
	cin>>str1>>str2;
	
	int len=max(str1.size(),str2.size());
	
	int carry=0;
	
	for(int i=0;i<len;i++){
		int a=0,b=0;
		
		if(str1.size()){
			a=str1.back()-'0';	
			str1.pop_back();
		}
		
		if(str2.size()){
			b=str2.back()-'0';
			str2.pop_back();
		}
		
		ret+=to_string((a+b+carry)%10);
		
		carry=(a+b+carry)/10;
	}
	
	if(carry)
		ret+=to_string(carry);
	
	reverse(ret.begin(),ret.end());
	cout<<ret;
	return 0;
}