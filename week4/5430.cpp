#include<bits/stdc++.h>
using namespace std;

int t,n;
string cmd,str;

void parse(string&line,deque<int>&d){
	auto start=line.find('[');
	auto last=line.find(']');
	
	if(start==string::npos||last==string::npos){
		return;
	}
	
	line=line.substr(1, line.length() - 2);
	
	istringstream iss(line);
	char seperator=',';
	string num;
	
	while(getline(iss,num,seperator)){
		d.push_back(stoi(num));
	}
}

void solve(){
	string cmd,str;
	
	cin>>cmd>>n>>str;
	deque<int>d;
	
	parse(str,d);
	
	bool has_error=false,is_reversed=false;
	for(char c:cmd){
		if(c=='R'){
			is_reversed=!is_reversed;
		}else if(c=='D'){
			if(d.empty()){
				has_error=true;
				break;
			}
			
			if(is_reversed){
				d.pop_back();
			}else{
				d.pop_front();
			}
		}
	}
	
	if (has_error) {
        cout << "error\n";
    } else {
        cout << "[";
        if (!d.empty()) {
            // 뒤집힌 상태에 따라 다른 방향으로 출력
            if (!is_reversed) {
                for (size_t i = 0; i < d.size(); ++i) {
                    cout << d[i] << (i == d.size() - 1 ? "" : ",");
                }
            } else {
                for (size_t i = 0; i < d.size(); ++i) {
                    cout << d[d.size() - 1 - i] << (i == d.size() - 1 ? "" : ",");
                }
            }
        }
        cout << "]\n";
    }
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}