#include<bits/stdc++.h>
using namespace std;
int n,t;
int dfs(int m,int s){ //从m开始搜索，以s为根的树的方案数 
	int ans=1;
	for(int i=m;i*i<=s;i++){   //搜索合适的子树 
		if(s%i==0 && s/i>=i){
			ans+=dfs(i,s/i); //把子树的方案加起来 ，注意子树是从i开始搜索的,因为a2>=a1 
		} 
	}
	return ans;
} 
int main(){
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		cout<<dfs(2,x)<<endl;	
	}
	return 0;
}
