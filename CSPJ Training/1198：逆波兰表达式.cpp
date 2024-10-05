#include<iostream> 
#include<string>
#include <stdlib.h>
using namespace std;
typedef long long ll; //把long long 写成 ll 

/*
dfs(1): 读到*  return 23*59=> ans
dfs(2): 读到+  return 11.0+12.0 =>23
dfs(3): 读到"11.0"   return 11.0
dfs(4): 读到"12.0"   return 12.0
dfs(5): 读到+  return 24+35 =>59
dfs(6): 读到"24.0"   return 24
dfs(7): 读到"35.0"   return 35
*/



double dfs(){
	string str;
	cin>>str;
	if(str=="*")
		return dfs()*dfs();
	else if(str=="/")
		return dfs()/dfs();
	else if(str=="+")
		return dfs()+dfs();
	else if(str=="-")
		return dfs()-dfs();
	else 
		//将string"12.0"=> double 12.0
		//str.c_str()是将string"12.0"转换成字符数存储
		//atof 是将字符数转换成double 
		return atof(str.c_str());
	
}


int main(){
	double ans =dfs();
	printf("%lf\n", ans);
	
	return 0;
}
