#include<bits/stdc++.h>
using namespace std;
/*
	2.花式排序
		a  12   185
		b  12   190
		c  11   175
		d  11   195
	    从小到大，先按年龄排，如果年龄相同，就按身高排
		c d a b
		结构体 

*/

//定义一个复合类型 
struct node{ //新的数据类型，这个数据类型是一个复合类型 
	string name; //a
	int age; //12
	int hei; //185	
};
node arr[10]; 


bool cmp(node a,node b){ //a是前一个数，b是后一个数 
	if(a.age==b.age)
		return a.hei<b.hei;
	return a.age<b.age;
}
int main(){
	//存 
	arr[1]={"a",12,185};
	arr[2]={"b",12,190};
	arr[3]={"c",11,175};
	arr[4]={"d",11,195};
	//取
	//a  12   185
//	cout<<arr[1].name<<" "<<arr[1].age<<" "<<arr[1].hei;
	sort(arr+1,arr+1+4,cmp);
	for(int i=1;i<=4;i++)
		cout<<arr[i].name<<" ";

	return 0;
}
