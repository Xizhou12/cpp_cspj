#include<bits/stdc++.h>
using namespace std;
typedef long long ll; //把long long 写成 ll 
int n,k;
//自底向上 
ll dfs(int s,int m){ //把前s个不同的苹果，放入m个相同的盘子的方案数
	//递归的出口 
	if(s==1|| m==1 || s==m)
		return 1;
	//考虑最后一个苹果怎么放   an单独放+和人家一起放 
	return dfs(s-1,m-1)+dfs(s-1,m)*m;
	
}


int main(){
	cin>>n>>k;
	cout<<dfs(n,k);
	
	
	return 0;
}
