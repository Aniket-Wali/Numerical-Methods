#include<iostream>
using namespace std;
void table(int y[],int n)
{
	if(n==1)
	{
		
		cout<<"end";
	}
	else if (n==0)
	{
		cout<<"empty table ";
	}
	else
	{
		int z[n-1];int m=1;
		for(int i = 0;i<n;i++)
		{
			z[i+1]=(-1)*(y[i]-y[m]);
			m++;
		}
		cout<<"\t";
		cout<<"difference table : \n";
		for(int i=0;i<n-1;i++)
		{
			cout<<z[i]<<endl;
		}
		cout<<"\n";
		table(z,n-1);
	}
}
int main()
{
	int x[100],y[100],h,n,x1;
	cout<<"enter value of h and x0 ? "<<endl;
	cin>>h>>x1;
	cout<<"enter how many x you want -> length ?"<<endl;
	cin>>n;
	cout<<"enter values of y:"<<endl;
	for(int i=0;i<n;i++)
	{
		x[i]=x1+(i*h);
		cin>>y[i];
	}
	cout<<"x"<<"		"<<"y"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"x"<<i<<"="<<x[i]<<"		"<<"y"<<i<<"="<<y[i]<<endl;
	}
	cout<<"\n";
	table(y,n);
	
}