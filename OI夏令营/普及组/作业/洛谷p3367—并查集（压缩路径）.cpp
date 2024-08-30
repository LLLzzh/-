# include <iostream>
using namespace std;
int find_top(int *a,int k)
{
	while(a[k] != k) k = a[k];
	return k;
}
int main(void)
{
	int n,m,p,x,y,*a,v,u;
	cin>>n>>m;
	a = new int[n+5];
	for(int i = 0;i < n+5;i++) a[i] = i;
	while(m--)
	{
		cin>>p>>x>>y;
		v = find_top(a,x);u = find_top(a,y);
		if(p == 1)
		{
			if(v > u) a[v] = u;
			else a[u] = v; 
		}
		else
		{
			cout<<(v == u?"Y":"N")<<endl;
		}
	}
	return 0;
 } 
