# include <iostream>
# include <cmath>
# include <cstdio>
using namespace std;
double f(double a,double b,double c,double d,double x)
{
	return a*pow(x,3) + b*pow(x,2) + c*x + d; 
}
void solve(double a,double b,double c,double d,int i)
{
	double left,right,mid;
	left = i;right = i+1;
	while(right-left > 0.001)
	{
		mid = (left+right)/2;
		if(f(a,b,c,d,mid) == 0)
		{
			printf("%.2f ",mid);
			return ;
		}
		else if(f(a,b,c,d,mid) > 0)
		{
			if(f(a,b,c,d,right) > 0) right = mid;
			else left = mid;
		}
		else if(f(a,b,c,d,mid) < 0)
		{
			if(f(a,b,c,d,right) < 0) right = mid;
			else left = mid;
		}
	}
	printf("%.2f ",(left+right)/2);
}
int main(void)
{
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i = -100;i < 100;i++)
	{
		if(f(a,b,c,d,double(i)) == 0) printf("%.2f ",double(i));
		else if(f(a,b,c,d,i)*f(a,b,c,d,i+1) < 0) solve(a,b,c,d,i);
	}
	cout<<endl; 
	return 0;
}  
