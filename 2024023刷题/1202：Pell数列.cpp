#include<iostream> 
#include<string>
#include <stdlib.h>
using namespace std;
typedef long long ll; 
const int N=1E6+5;
int t;
ll f[N];  //������ ��i�����Ƕ��٣�
ll dfs(int s){ //쳲����� ��s�����Ƕ��٣� 
	if(f[s]!=0) return f[s];
	//���������������ϵ����
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
