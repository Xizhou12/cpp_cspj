#include<iostream> 
#include<string>
#include <stdlib.h>
#include<stack>
using namespace std;
typedef long long ll;
int t;
ll dfs(int s,int m){ //s���ޱ��ƻ������m���ޱ������
	if(s==1 || m==1 || s==0) return 1;
	if(s<m) return dfs(s,s);//���ӱ�ƻ����	
	if(s>=m){
		//��һ��         ���� 
		return dfs(s,m-1)+dfs(s-m,m);
	} 
}


int main(){
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y)<<endl;
	}
	
	return 0;
}
