# include <iostream>
using namespace std;
int main(void)
{
	int n,_min,ans,sum = 0,k;
	cin>>n>>k;
	ans = sum = k;
	_min = min(k,0);
	for(int i = 1;i < n;i++)
	{
		cin>>k;
		sum += k;
		if(sum-_min > ans) ans = sum-_min;
		if(sum < _min) _min = sum;
	}
	cout<<ans<<endl;
	return 0;
}
