#include<bits/stdc++.h>
using namespace std;

int m,bitmask=0;
void go(string &str){
	auto space_pos=str.find(' ');
	
	auto cmd=str.substr(0,space_pos);
	int num=stoi(str.substr(space_pos+1));
	
	int bit=1<<num;
	
	if(cmd=="add"){
		bitmask|=bit;	
	}else if(cmd=="remove"){
		bitmask&=(~bit);
	}else if(cmd=="check"){
		cout<<((bitmask&bit)?1:0)<<'\n';
	}else if(cmd=="toggle"){
		bitmask^=bit;
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> m;
	// getchar() 대신 cin.ignore() 사용
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	std::string str;
	for(int i=0;i<m;i++){
		getline(cin,str);
		
		if(str.find("all")!=string::npos)
			bitmask=(1<<21)-1;
		else if(str.find("empty")!=string::npos)
			bitmask=0;
		else
			go(str);
	}
	return 0;
}