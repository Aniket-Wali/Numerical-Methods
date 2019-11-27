#include<iostream>
using namespace std;
float term(int i,float value,float x[])
{
	float pro = 1;
	for(int j=0;j<i;j++)
	{
		pro=pro*(value-x[j]);
	}
	return pro;
}
void table(float x[],float y[][10],int n)
{
	
	for(int i =1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			y[j][i]=(y[j][i+1]-y[j+1][i-1])/(x[j]-x[i+j]);
		}
	}
}
float formula(float v,float x[],float y[][10],int n)
{
	float sum = y[0][0];
	for(int i=1;i<n;i++)
	{
		sum=sum+(term(i,v,x)*y[0][i]);
	}
	return sum;
}
void print(float y[][10],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			cout<<y[i][j]<<"\t";
		}	cout<<endl;
		
	}
}
int main()
{
	int n=4;
	float value,sum,y[10][10];
	float x[]={5,6,9,11};
	y[0][0]=12;
	y[1][0]=13;
	y[2][0]=14;
	y[3][0]=16;
	table(x,y,n);
	print(y,n);
	cout<<"enter value to be interpolated \n";
	cin>>value;
	cout<<"value at"<<value<<"="<<formula(value,x,y,n);
	return 0;
}