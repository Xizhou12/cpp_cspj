#include<iostream> 
#include<string>
#include <stdlib.h>
using namespace std;
typedef long long ll; 
const int N=1E6+5;
int t;
ll f[N];  //波那契 第i个数是多少？
ll dfs(int s){ //斐波那契 第s个数是多少？ 
	if(f[s]!=0) return f[s];
	//大问题与子问题关系建立
	ll ans= dfs(s-2)%32767+2*dfs(s-1)%32767;
	f[s]=ans;
	return ans; 
}


int main(){
	cin>>t;
	f[1]=1;
	f[2]=2;
	while(t--){
		int x;
		cin>>x;
		cout<<dfs(x)%32767<<endl;
	}
	
	return 0;
}
