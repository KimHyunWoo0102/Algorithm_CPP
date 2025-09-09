#include<bits/stdc++.h>
using namespace std;

 

int n;
int mp,mf,ms,mv;
int ret_cost=INT_MAX,ret_mask;
string ret;
struct A{
	int p;
	int f;
	int s;
	int v;
	int c;
};

A a[30];

bool cmp(A&a1){
	if(a1.p<mp)return false;
	if(a1.f<mf)return false;
	if(a1.s<ms)return false;
	if(a1.v<mv)return false;
	
	return true;
}
void go(int num){
	A tmp={0,0,0,0,0};
	string str;
	for(int i=0;i<n;i++){
		if(num&(1<<i)){
			tmp.p+=a[i].p;
			tmp.f+=a[i].f;
			tmp.c+=a[i].c;
			tmp.s+=a[i].s;
			tmp.v+=a[i].v;
			str+=to_string(i+1)+" ";
		}
	}
	
	if(cmp(tmp)){
		if(ret_cost>tmp.c){
			ret_cost=tmp.c;
			ret=str;
		}else if(ret_cost==tmp.c){
			ret=min(ret,str);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
	
	cin>>n;	
	
	cin>>mp>>mf>>ms>>mv;
	
	for(int i=0;i<n;i++){
		cin>>a[i].p>>a[i].f>>a[i].s>>a[i].v>>a[i].c;		
	}
	
	for(int i=1;i<(1<<n);i++){
		go(i);
	}
	
	if(ret_cost==INT_MAX){
		cout<<-1;
		return 0;
	}
	
	cout<<ret_cost<<'\n';
	cout<<ret;
	return 0;
}
