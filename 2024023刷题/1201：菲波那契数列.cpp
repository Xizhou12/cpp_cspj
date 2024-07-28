#include<iostream> 
#include<string>
#include <stdlib.h>
using namespace std;
typedef long long ll; 
int t;
ll dfs(int s){ //斐波那契 第s个数是多少？ 
	//边界
	if(s==1 || s==2)
		return 1; 
	//大问题与子问题关系建立
	return dfs(s-2)+dfs(s-1); 
}


int main(){
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		cout<<dfs(x)<<endl;
	}
	
	return 0;
}
