# include <iostream>
using namespace std;
int main(void)
{
	int l,n,m,*a,left,right,mid,k,d;
	cin>>l>>n>>m;
	a = new int [n];
	for(int i = 0;i < n;i++) cin>>a[i];
	left = 0;right = l;
	while(1)
	{
		mid = (left+right)/2;
		d = k = 0;
		for(int i = 0;i < n;i++)
		{
			if(a[i]-d > mid) d = a[i];
			else k++;
		}
		if(k <= m) left = mid;
		else right = mid;
		if(left == right || left == (left+right)/2) break;
	}
	cout<<right<<endl;
	return 0;
} 
