#include<iostream> 
#include<string>
#include <stdlib.h>
#include<stack>
using namespace std;
typedef long long ll;
int n;

ll dfs(int s){ //��ǰs��̨����Ҫ�ķ����� 
	if(s==1) return 1;
	if(s==2) return 2;
	return dfs(s-2)+dfs(s-1);
	
	
}

int main(){
	while(cin>>n){
		cout<<dfs(n)<<endl;
	}
	
	return 0;
}
