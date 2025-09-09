#include<bits/stdc++.h>
using namespace std;

int n;
int arr[30],cpy[30];
int ret=INT_MAX;

void print(){
	for (int i = 0; i < n; i++) {
    // k를 n-1부터 0까지 감소시키며 각 비트를 확인
    	for (int k = n - 1; k >= 0; k--) {
       	 	if (cpy[i] & (1 << k)) { // k번째 비트가 1이면
         	   cout << '1';
        	} else {
            	cout << '0';
        	}
    	}
    	cout << '\n';
	}
	cout<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c;
			cin>>c;
			arr[i]=arr[i]<<1;
			if(c=='T')arr[i]|=1;
		}
	}
	
	for(int i=0;i<(1<<n);i++){
		int sum=0;
		memcpy(cpy,arr,sizeof(cpy));
		
		for(int row=0;row<n;row++){
			if(i&(1<<row)){
				cpy[row]=~cpy[row];
			}
		}
		
		for(int col=0;col<n;col++){
			int cnt=0;
			for(int row=0;row<n;row++){
				if(cpy[row]&(1<<col))cnt++;
			}
			
			if(cnt>n-cnt){
				cnt=n-cnt;
			}
			
			sum+=cnt;
		}
		
		ret=min(sum,ret);
	}
	
	
	cout<<ret;
	return 0;
}
