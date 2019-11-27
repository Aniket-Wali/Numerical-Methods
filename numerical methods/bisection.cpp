#include<iostream>
 
using namespace std;
 
//function used is x^3-4x-9
double find_x(double x)
{
    return x*x*x - 4*x -9;
}
 
double e=0.00001;
double c;
int count=0,flag=0;
 
void bisection(double a,double b)
{
    if(find_x(a) * find_x(b) >= 0)
    {
        cout<<"Incorrect a and b";
        cout<<"f(x"<<a<<") = "<<find_x(a)<<endl;
        cout<<"f(x"<<b<<") = "<<find_x(b)<<endl;
        cout<<"a nd b should be of opposite sign !! ";
        return;
    }
 
    c = a;
 
    while ((b-a) >= e)
    {
        c = (a+b)/2;
        count++;
        if (find_x(c) == 0.0){
            cout << "x"<<count<<"=" << c<<endl;                //finding correct root =0
            cout<<"f(x"<<count<<") = "<<find_x(c)<<endl;
            flag=1;
            break;
        }
        else if (find_x(c)*find_x(a) < 0){
                cout << "x"<<count<<"=" << c<<endl;
                cout<<"f(x"<<count<<") = "<<find_x(c)<<endl;
                b = c;
        }
        else{
                cout <<"x"<<count<<"="<< c<<endl;
                cout<<"f(x"<<count<<") = "<<find_x(c)<<endl;
                a = c;
        }
    }
}


int main()
{
    double a,b;
    a=1;
    b=2;
 
    cout<<"The function used is x^3-4x-9\n";
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    bisection(a,b);
    cout<<"\n\n";
    if(flag==1)
    {
        cout<<"Accurate Root calculated is = NULL "<<endl;    
    }
    else
    {
        cout<<"Accurate Root calculated is = "<<c<<endl;
    }
    a=2;
    b=3;
 
    cout<<"The function used is x^3-4x-9\n";
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    bisection(a,b);
    cout<<"\n\n";
    cout<<"Accurate Root calculated is = "<<c<<endl;
    
    
 
     
 
    return 0;
}
