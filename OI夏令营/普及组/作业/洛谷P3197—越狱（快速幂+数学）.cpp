# include <iostream>
using namespace std;
typedef long long ll;
const int mod = 100003;
ll q_pow(ll a,ll n)
{
	ll ans = 1;
	while(n)
	{
		if(n&1) ans *= a;
		n /= 2; a *= a;
		ans %= mod; a %= mod;
	}
	return ans;
} 
int main(void)
{
	ll sum,m,n,imposs;
	cin>>m>>n;
	sum = q_pow(m,n);
	imposs = q_pow(m-1,n-1) * (m%mod);
	imposs %= mod;
	sum -= imposs;
	if(sum < 0) sum += mod;
	cout<<sum<<endl;
	return 0;
}
