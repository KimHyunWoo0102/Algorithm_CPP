#include<bits/stdc++.h>
using namespace std;
vector<int> v={0,1,2,3,4,5,6,7,8,9};
char arr[20];
long long n;
string ret_max, ret_min; // 문자열로 처리
bool eval(int d1,char op,int d2){
	if(op=='>')
		return d1>d2;
	else if(op=='<')
		return d1<d2;
	
	return false;
}

void go(){
	int num=n+1;
	
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		scanf(" %c",&arr[i]);
	do{		
		string s;
		bool f=true;
		for(int i=0;i<n;i++){
			bool eval_result = eval(v[i], arr[i], v[i + 1]); // 결과를 변수에 저장
   				if (!eval_result) {
        			f = false;
        			break; // 이미 실패했으므로 더 이상 검사할 필요 없음
    			}
		}
		
		if(f){
            string current_num = "";
            // n+1개의 숫자만 사용해서 문자열 생성
            for(int i = 0; i < n + 1; i++){
                current_num += to_string(v[i]);
            }

            // 처음 찾은 숫자를 min/max 초기값으로 설정
            if(ret_min.empty()) {
                ret_min = current_num;
            }
            ret_max = current_num; // 순열은 오름차순으로 생성되므로, 마지막에 찾은 것이 최댓값
        }
	}while(next_permutation(v.begin(),v.end()));
	
	cout<<ret_max<<'\n'<<ret_min<<'\n';
	return 0;
}