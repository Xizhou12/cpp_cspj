#include<iostream> 
#include<string>
#include <stdlib.h>
using namespace std;
typedef long long ll; 
int t;
ll dfs(int s){ //쳲����� ��s�����Ƕ��٣� 
	//�߽�
	if(s==1 || s==2)
		return 1; 
	//���������������ϵ����
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
