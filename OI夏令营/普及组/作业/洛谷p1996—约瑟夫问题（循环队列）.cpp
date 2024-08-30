# include <iostream>
using namespace std;
int main(void)
{
	int n,k,j = -1,r = 0,*p;
	cin>>n>>k;
	p = new int [n];
	for(int i = 0;i < n;i++) p[i] = 0;
	for(int i = 0;i < n;i++)
	{
		while(r != k)
		{
			j++;
			if(j == n) j = 0;
			if(p[j] == 0) r++;
		}
		p[j] = 1;
		cout<<j+1<<" ";
		r = 0;
	}
	return 0;
}
