# include <iostream>
using namespace std;
const int mod = 6662333;
long long quick_pow(long long a,long long n)
{
	long long res = 1;
	while(n)
	{
		if(n&1) res *= a;
		n /= 2; a *= a;
		res %= mod; a %= mod; 
	}
	return res;
} 
int main(void)
{
	long long n;
	cin>>n;
	cout<<quick_pow(2,n-1)<<endl;
	return 0;
}
