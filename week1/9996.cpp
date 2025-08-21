#include<bits/stdc++.h>
using namespace std;

string str;
string input;
int n;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	
	cin>>str;
	
	auto idx=str.find("*");
	
	auto sLen=idx-0;
	auto lLen=str.size()-idx-1;

	for(int i=0;i<n;i++)
	{
		cin>>input;
		if (input.size() < sLen+lLen) {
    	cout << "NE\n";
    	continue;
		}
		
		if(str.substr(0,sLen)==input.substr(0,sLen)&&str.substr(idx+1)==input.substr(input.size()-lLen)){	
			cout<<"DA\n";	
		}
		else
			cout<<"NE\n";
	}
	
	return 0;
}