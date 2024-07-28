#include<iostream> 
#include<string>
#include <stdlib.h>
using namespace std;
typedef long long ll; //��long long д�� ll 

/*
dfs(1): ����*  return 23*59=> ans
dfs(2): ����+  return 11.0+12.0 =>23
dfs(3): ����"11.0"   return 11.0
dfs(4): ����"12.0"   return 12.0
dfs(5): ����+  return 24+35 =>59
dfs(6): ����"24.0"   return 24
dfs(7): ����"35.0"   return 35
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
		//��string"12.0"=> double 12.0
		//str.c_str()�ǽ�string"12.0"ת�����ַ����洢
		//atof �ǽ��ַ���ת����double 
		return atof(str.c_str());
	
}


int main(){
	double ans =dfs();
	printf("%lf\n", ans);
	
	return 0;
}
