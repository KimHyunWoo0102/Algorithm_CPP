#include<bits/stdc++.h>
using namespace std;

int n;
const int max_size=70;
int arr[max_size][max_size];

bool is_merge(int sx,int sy,int ex,int ey){
	if(sx>ex&&sy>sy)return true;
	
	int pivot=arr[sy][sx];

	for(int i=sy;i<ey;i++){
		for(int j=sx;j<ex;j++){
			if(pivot!=arr[i][j])return false;
		}
	}	
	
	return true;
}
void go(int sx,int sy,int ex,int ey){
	if(sx==ex||sy==ey)return;
	cout<<"(";
	
	int midx=(sx+ex)/2;
	int midy=(sy+ey)/2;
	
	
	
	if(is_merge(sx,sy,midx,midy))cout<<arr[sy][sx];
	else go(sx,sy,midx,midy);
	
	if(is_merge(midx,sy,ex,midy))cout<<arr[sy][midx];
	else go(midx,sy,ex,midy);
	
	if(is_merge(sx,midy,midx,ey))cout<<arr[midy][sx];
	else go(sx,midy,midx,ey);
	
	if(is_merge(midx,midy,ex,ey))cout<<arr[midy][midx];
	else go(midx,midy,ex,ey);
	cout<<")";
}

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			scanf("%1d",&arr[i][j]);
	}
	if(is_merge(0,0,n,n))cout<<arr[0][0];
	else go(0,0,n,n);
	
	return 0;
}