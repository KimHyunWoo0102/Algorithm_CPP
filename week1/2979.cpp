#include<bits/stdc++.h>
using namespace std;

int charge[4];
int timearr[104];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	for(int i=1;i<=3;i++){
		cin>>charge[i];
	}
	
	int start,end;
	int mini=100,maxi=0;
	
	for(int i=0;i<3;i++){
		cin>>start>>end;
		
		if(mini>start)
		{
			mini=start;
		}
		
		if(maxi<end){
			maxi=end;
		}
		
		for(int i=start;i<end;i++){
			timearr[i]++;
		}
	}
	
	int sum=0;
	
	for(int i=0;i<100;i++)
	{
		sum+=timearr[i]*charge[timearr[i]];	
	}	
	
	cout<<sum;
	return 0;
}