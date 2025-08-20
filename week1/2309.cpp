#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n=9,r=7;

int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int tmp;
	
	for(int i=0;i<n;i++){
		cin>>tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(),v.end());
	int pivot=accumulate(v.begin(),v.end(),0)-100;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(v[i]+v[j]==pivot){
				for(int k=0;k<n;k++){
					if(k==i||k==j)continue;
					cout<<v[k]<<'\n';
				}
				exit(0);
			}
		}
	}
}