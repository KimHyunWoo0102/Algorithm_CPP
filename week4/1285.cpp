#include<bits/stdc++.h>
using namespace std;

int n;
char arr[23][23],copy_arr[23][23];
int ret=INT_MAX;
void flip_row(int row){
	for(int i=0;i<n;i++){
		if(copy_arr[row][i]=='T')
			copy_arr[row][i]='H';
		else
			copy_arr[row][i]='T';
	}
}

void flip_col(int col){
	for(int i=0;i<n;i++){
		if(copy_arr[i][col]=='T')
			copy_arr[i][col]='H';
		else
			copy_arr[i][col]='T';
	}
}

int calcul(){
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(copy_arr[i][j]=='T')cnt++;
		}
	}
	
	return cnt;
}
void go(int row){
	memcpy(copy_arr,arr,sizeof(copy_arr));
	
	for(int i=0;i<n;i++){
		if(row&(1<<i)){
			//µÚÁý±â
			flip_row(i); 
		}
	}
	
	for(int col=0;col<n;col++){
		int cnt=0;
		for(int row=0;row<n;row++){
			if(copy_arr[row][col]=='H')cnt++;
		}
		
		if(cnt<n-cnt)flip_col(col);
	}
	
	ret=min(ret,calcul());
}
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}	
	
	
	for(int i=0;i<(1<<n);i++){
		go(i);
	}
	
	
	cout<<ret;
	
	return 0;
}
