# include <iostream>
using namespace std;
struct info
{
	int d,st,ed;
};
bool solve(int *a,info *b,int range,int n)
{
	long long *p,k = 0; p = new long long [n];
	for(int i = 0;i < n;i++) p[i] = 0;
	for(int i = 0;i < range;i++)
	{
		p[b[i].st-1] += b[i].d;
		p[b[i].ed] -= b[i].d;
	}
	for(int i = 0;i < n;i++)
	{
		k += p[i];
		if(k > a[i]) return false;
	}
	return true;
}
int main(void)
{
	int n,m,*a,d,st,ed,left,right,mid;
	info *b;
	cin>>n; a = new int [n];
	cin>>m; b = new info [m];
	for(int i = 0;i < n;i++) cin>>a[i];
	for(int i = 0;i < m;i++) cin>>b[i].d>>b[i].st>>b[i].ed;
	if(solve(a,b,m,n)) cout<<"0"<<endl;
	else if(!solve(a,b,1,n)) cout<<"-1\n1"<<endl;
	else
	{
		left = 1;right = m;
		while(right-left > 3)
		{
			mid = (left+right)/2;
			if(solve(a,b,mid,n)) left = mid;
			else right = mid;
		}
		for(int i = left;i <= right;i++)
			if(solve(a,b,i,n) && !solve(a,b,i+1,n)) cout<<"-1\n"<<i+1<<endl;
	}
	return 0;
}
