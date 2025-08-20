#include<bits/stdc++.h>

using namespace std;

pair<int,int> p;
string split(string origin,string delimeter){
	string ret="";
	
	auto start=0;
	auto end=origin.find(delimeter);
	
	while(end!=string::npos){
		ret+=origin.substr(start,end-start);
		start=end+delimeter.size();
		end=origin.find(delimeter,start);
	}
	
	ret+=origin.substr(start,end-start);
	return ret;
}
vector<int> v; 
int b[5];  


int main(){ 
    for(int i=0;i<20;i++){
    	v.push_back(i);
		v.push_back(i);
		}
		
	auto max=max_element(v.begin(),v.end());
	
	
	cout<<*max<<'\n';
	cout<<int(max-v.begin());
//	cout<<"sum : "<<sum<<endl;
} 
      
