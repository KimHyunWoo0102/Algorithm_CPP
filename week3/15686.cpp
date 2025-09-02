#include<bits/stdc++.h>
using namespace std;

#define y1 adsdawd
int n,m;

int arr[54][54];


vector<pair<int,int>> c,h,pick;

int min_ret=INT_MAX;
void print(){
	cout<<"combi!!"<<'\n';
	for(const auto&it:pick){
		cout<<it.first<<" "<<it.second<<'\n';
	}
	cout<<'\n';
}

int dist(pair<int,int>p1,pair<int,int>p2){
	return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

void go(){
	int ret=0;
	for(auto&home:h){
		int md=INT_MAX;
		for(auto&ch:pick){
			md=min(md,dist(home,ch));
		}
		
		ret+=md;
	}
	min_ret=min(ret,min_ret);
}
void combi(int start){
	if(pick.size()==m){
		go();
		return;
	}
	
	for(int i=start+1;i<c.size();i++){
		pick.push_back(c[i]);
		combi(i);
		pick.pop_back();
	}
}
int main(){
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==2)c.push_back({i,j});
			else if(arr[i][j]==1)h.push_back({i,j});
		}
	}
	
	combi(-1);
	cout<<min_ret;
	return 0;
}