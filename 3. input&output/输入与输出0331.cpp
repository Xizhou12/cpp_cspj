#include<iostream>
#include<iomanip> //Ϊ���ܹ�ʹ��setprecision 
#include <stdio.h>

using namespace std;
/*
	1.����
		������򿪵��ԣ����ٴ򿪵���
		��ҵ�����ϸ����
			��ҵ?�Ű�һ��ͨ
	2.�Ͽ�
		û���飬ֻ�п��ð���(PPT) 
		1����֮�ڰ�֪ʶ������ A4��ֽ��д��������
		��ʱ���������Ǵ�ҽ���
		
	3.��������
		����   ��׼  90��/���� Ӣ��   һ��������ߵ����ˮƽ 
		��ô��?https://dazi.kukuw.com/
			ÿ���˶����У�����
		������ÿ����10���ӣ�һ�춼���� 
		
	4.װ������
		devc++ 
		
		
	֪ʶ��ϵ
		0.ͨ��֪ʶ 
		1.���������
			1.1���
			c++:
				��� cout<<���� 
				���� cin>>���� 
			c:
				��� printf("%d",num) 
				���� scanf("%d",&num)
					%d ����
					%f С�� float
					%lf С�� double	
					
			1.2����С��������:
				c++:
					#include<iomanip>
					cout<<fixed<<setprecision(2)<<a; �������� 
				c:(Ч�ʸ�):
					printf("%7.3lf",a); 
						%m.nlf
							n���Ǳ�����λС��
							m�������ʵ�ĳ��ȴ���m,����ʵ���
											 С��m ,ǰ���ո� 		
					 3.1415926
					 %3.2
			1.3һ��������������
				c++:
					int a,b;
					cin>>a>>b
					�����ʱ�� �Կո񣬻س���tabһ����������ϾͿ�����
				c:
					scanf("%d%d") 
					 
				 
		2.��������
			c++
				�ַ���
					string
				����
					int
				С��
					float double 
				
				 
		3.�����
		4.�߼�
		5.���� ���ѣ� 
		6.ָ�루�ѣ�
		7.����
		8.�ṹ��
		9.�������C++) cspj���ٿ� 
		10.�㷨 
	
	 
		 
		 
			 


*/
//c++����������� 
void f1(){
	string str; //����һ������
	cin>>str;  //�ֶ����� 
	cout<<str;  
	
}
//c����������� 
void f2(){
	int b; //����һ���������� 
	scanf("aa%dbb",&b);//c������
	//%d����   %f %lf 
	printf("����: %d �ٺ� ",b);  //C����� 	
	
}
//��һ�� �����û�����һ���������������������������� 
//c++����С������ 
void f3(){
	//�뱣��7λ 
	double a=3.14792611111111111111;
	cout<<fixed<<setprecision(2)<<a;
}
//c�ı���С�� 
void f4(){
	double a=3.1415926;
	printf("����:%8.2lf\n����:%8.3lf\n����: %8.4lf",a,a,a);	
	
}
//C++����������  
void f5(){
	int a,b;
	cin>>a>>b;
	cout<<a<<" "<<b; 
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d����%8d",a,b);
	
	return 0;
}
