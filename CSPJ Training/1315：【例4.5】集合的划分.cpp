#include<bits/stdc++.h>
using namespace std;
typedef long long ll; //��long long д�� ll 
int n,k;
//�Ե����� 
ll dfs(int s,int m){ //��ǰs����ͬ��ƻ��������m����ͬ�����ӵķ�����
	//�ݹ�ĳ��� 
	if(s==1|| m==1 || s==m)
		return 1;
	//�������һ��ƻ����ô��   an������+���˼�һ��� 
	return dfs(s-1,m-1)+dfs(s-1,m)*m;
	
}


int main(){
	cin>>n>>k;
	cout<<dfs(n,k);
	
	
	return 0;
}
