#include<iostream>
using namespace std;
struct data
{
	int x,y;
};
double interpolate(data f[],int xi, int n)
{
	double r=0;
	for(int i=0;i<n;i++)
	{
		double term=f[i].y;
		for(int j=0;j<n;j++)
		{
			if (j!=i)
			{
				term = term *(xi - f[j].x)/(double(f[i].x-f[j].x));
			}
		}    
		r += term;                                                                                                                                                                
	}
	return r;
}
int main()
{
	data f[]={{0,2},{1,3},{2,12},{5,147}};
	cout<<"value of f(4) is"<<interpolate(f,4,5);
	return 0;
}