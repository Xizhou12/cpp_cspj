#include<iostream> 
#include<string>
#include <stdlib.h>
#include<stack>

using namespace std;
typedef long long ll; 
struct node{
	int idd; //����ֵ 
	char ch; 
};
void check(string str){
	stack<node> sk;
	for(int i=0;i<str.size();i++ ){
		char ch=str[i];
		if(ch=='('){
			sk.push({i, ch});
		}else if(ch==')'){
			if(!sk.empty() && sk.top().ch=='(')
				sk.pop();
			else
				sk.push({i,ch});
		}
	}
	cout<<str<<endl;
	int arr[str.size()]={};//Ĭ��Ϊ0
	while(!sk.empty()){
		node n1=sk.top();
		sk.pop();
		arr[n1.idd]= (n1.ch=='('?1:2); //��1  )2 
	} 
	
	
	for(int i=0;i<str.size();i++)
		if(arr[i]==1)
			cout<<'$';
		else if(arr[i]==2)
			cout<<'?';
		else 
			cout<<' ';
	
	
}

int main(){
	string str;
	while(cin>>str){ //����EOF�ͽ���(ctrl+z),end of file 
		check(str);
		cout<<endl;
		
	}
	return 0;
}
