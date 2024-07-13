#include<iostream>
#include<iomanip> //为了能够使用setprecision 
#include <stdio.h>

using namespace std;
/*
	1.纪律
		我让你打开电脑，你再打开电脑
		作业必须严格完成
			作业?信奥一本通
	2.上课
		没有书，只有课堂版书(PPT) 
		1个月之内把知识点梳理 A4的纸手写，交给我
		随时上来给我们大家讲课
		
	3.基本技能
		打字   标准  90字/分钟 英文   一个月内提高到这个水平 
		怎么练?https://dazi.kukuw.com/
			每个人都不行！！！
		方法：每天练10分钟，一天都不断 
		
	4.装编译器
		devc++ 
		
		
	知识体系
		0.通用知识 
		1.输入与输出
			1.1框架
			c++:
				输出 cout<<变量 
				输入 cin>>变量 
			c:
				输出 printf("%d",num) 
				输入 scanf("%d",&num)
					%d 整数
					%f 小数 float
					%lf 小数 double	
					
			1.2保留小数的问题:
				c++:
					#include<iomanip>
					cout<<fixed<<setprecision(2)<<a; 四舍五入 
				c:(效率高):
					printf("%7.3lf",a); 
						%m.nlf
							n就是保留几位小数
							m，如果真实的长度大于m,就真实输出
											 小于m ,前被空格 		
					 3.1415926
					 %3.2
			1.3一次性输入多个变量
				c++:
					int a,b;
					cin>>a>>b
					输入的时候 以空格，回车，tab一个或多个的组合就可以了
				c:
					scanf("%d%d") 
					 
				 
		2.数据类型
			c++
				字符串
					string
				整数
					int
				小数
					float double 
				
				 
		3.运算符
		4.逻辑
		5.数组 （难） 
		6.指针（难）
		7.函数
		8.结构体
		9.面向对象（C++) cspj很少考 
		10.算法 
	
	 
		 
		 
			 


*/
//c++的输入与输出 
void f1(){
	string str; //定义一个变量
	cin>>str;  //手动输入 
	cout<<str;  
	
}
//c的输入与输出 
void f2(){
	int b; //定义一个整数变量 
	scanf("aa%dbb",&b);//c的输入
	//%d整数   %f %lf 
	printf("哈哈: %d 嘿嘿 ",b);  //C的输出 	
	
}
//出一题 ，请用户输入一个整数，再输出，哈哈你的整数是 
//c++保留小数问题 
void f3(){
	//想保留7位 
	double a=3.14792611111111111111;
	cout<<fixed<<setprecision(2)<<a;
}
//c的保留小数 
void f4(){
	double a=3.1415926;
	printf("哈哈:%8.2lf\n哈哈:%8.3lf\n哈哈: %8.4lf",a,a,a);	
	
}
//C++输入多个变量  
void f5(){
	int a,b;
	cin>>a>>b;
	cout<<a<<" "<<b; 
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d哈哈%8d",a,b);
	
	return 0;
}
