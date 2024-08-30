# include <iostream>
using namespace std;
int main(void)
{
	int n,l,k,ans_max = 0,ans_min = 0;
	cin>>l>>n;
	while(n--)
	{
		cin>>k;
		ans_min = max(ans_min,min(k,l+1-k));
		ans_max = max(ans_max,max(k,l+1-k));
	}
	cout<<ans_min<<" "<<ans_max<<endl;
	return 0; 
}
