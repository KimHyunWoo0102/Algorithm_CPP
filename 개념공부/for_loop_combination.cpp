#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[5]={1,2,3,4,5};
	int n=5,k=2,r=3;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++){
			cout<<i<<" "<<j<<'\n';
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++)
			{
				for(int l=k+1;l<n;l++)
					cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
			}
		}
	}
	return 0;
}