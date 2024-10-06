
#include <iostream>
using namespace std;
struct Node{
	int price;
	int start;
};
long long ans=0,cnt=0;//cnt 记录上次最后的时间 
Node a[100001];
int main()
{
	int n,type,price,start;
    int begin = 1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>type>>price>>start;
		if(type==0) //地铁票 
		{
			ans+=price;
			Node node={price,start};
			a[++cnt]=node;
		}
		else	//有机会使用以前的公车票 
		{	
			bool flag=false;
			for(int j=begin;j<=cnt;j++)
			{
				if(start-a[j].start>45){
                    begin ++;
                    continue;
                }
					
				else//要使用范围内 
				{
					if(a[j].price>=price)
					{
						a[j].price=0;//标志已使用
						flag=true;
		 				break;
					}
				}
			}
			if(flag==false)
				ans+=price;
		}
	}
	cout<<ans;
	return 0;
}
