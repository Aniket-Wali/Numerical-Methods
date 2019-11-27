#include<iostream>
#include<cmath> 
#include <cstdlib> 
using namespace std; 
double func(double x) 
{ 
	return x*x*x*x - x - 10.0;
	
} 
double derivFunc(double x) 
{ 
	return 4*x*x*x - 1;
} 
int main() 
{ 
	
	double e=0.0001,x1,xo=2.0;
	int count=0;
	clock_t start = clock();
	do
	{
		
		x1= xo - (func(xo)/derivFunc(xo));
		if(func(x1)==0)
		{
			count++;
			cout<<"root = "<<x1<<endl;
			break;
		}
		else
		{
			count++;
			cout<<x1<<endl;
			xo=x1;

		}

	}while(xo>=e);
	clock_t end = clock();
	double time = double(end - start)/CLOCKS_PER_SEC;
	cout<<"Time Elapsed for randomizequickSort : "<<time<<endl;

} 







