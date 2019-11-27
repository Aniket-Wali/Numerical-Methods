#include<iostream> 
#include<cstdlib>
using namespace std; 
#define MAX_ITER 1000000 
 
double func(double x) 
{ 
	return x*x*x*x - x - 10.0;
}
double derivFunc(double x) 
{ 
	return 4*x*x*x - 1;
} 
void regulaFalsi(double a, double b) 
{ 
	if (func(a) * func(b) >= 0) 
	{ 
		cout << "You have not assumed right a and b\n"; 
		return; 
	} 

	double c = a;  

	for (int i=0; i < MAX_ITER; i++) 
	{ 
		
		c = (a*func(b) - b*func(a))/ (func(b) - func(a)); 
	
		if (func(c)==0) 
			break; 

		 
		else if (func(c)*func(a) < 0) 
			b = c; 
		else
			a = c; 
	} 
	cout << "The value of root is : " << c; 
} 
void newton()
{ 
	
	double e=0.0001,x1,xo=2.0;
	int count=0;
	
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
			//cout<<x1<<endl;
			xo=x1;

		}

	}while(xo>=e);
	
} 
 
int main() 
{ 
	 
	double a =1, b = 2; 
	clock_t start = clock();
	regulaFalsi(a, b); 
	clock_t end = clock();
	double time = double(end - start)/CLOCKS_PER_SEC;
	cout<<"\n Time Elapsed for  : "<<time<<endl;
	clock_t start1 = clock();
	newton(); 
	clock_t end1 = clock();
	double time1 = double(end1 - start1)/CLOCKS_PER_SEC;
	cout<<"\n Time Elapsed  : "<<time1<<endl;
	

	return 0; 
} 
