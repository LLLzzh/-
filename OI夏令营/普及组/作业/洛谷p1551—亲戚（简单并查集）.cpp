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
	cin>>n>>m>>p;
	a = new int[n+5];
	for(int i = 0;i < n+5;i++) a[i] = i;
	while(m--)
	{
		cin>>x>>y;
		v = find_top(a,x);u = find_top(a,y);
		if(v > u) a[v] = u;
		else a[u] = v; 
	}
	while(p--)
	{
		cin>>x>>y;
		cout<<(find_top(a,x) == find_top(a,y)?"Yes":"No")<<endl;
	}
	return 0;
 } 
