#include<bits/stdc++.h>
using namespace std;
int n,t;
int dfs(int m,int s){ //��m��ʼ��������sΪ�������ķ����� 
	int ans=1;
	for(int i=m;i*i<=s;i++){   //�������ʵ����� 
		if(s%i==0 && s/i>=i){
			ans+=dfs(i,s/i); //�������ķ��������� ��ע�������Ǵ�i��ʼ������,��Ϊa2>=a1 
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
