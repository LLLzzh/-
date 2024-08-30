# include <iostream>
# include <cmath>
using namespace std;
typedef long long ll;
const int mod = 19260817;
ll quick_pow(ll a, ll n)//¼ÆËãa^n % mod
{
    ll re = 1;
    while(n)
    {
        if(n & 1)
            re = (re * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return re % mod;
}
int main(void)
{
	ll n,ans;
	cin>>n;
	if(n <= 2) ans = 0;
	else
	{
		ans = quick_pow(2,n)-(2*n%mod);
		ans %= mod;
		if(ans < 0) ans +=  mod;
	}	
	cout<<ans<<endl;
	return 0; 
} 
