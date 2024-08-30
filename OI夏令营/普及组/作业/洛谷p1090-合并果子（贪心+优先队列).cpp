# include <iostream>
# include <queue> 
using namespace std;
struct info
{
	int val;
	bool operator <(const info &a) const{return a.val < val;} 
};
int main(void)
{
	priority_queue<info> a;
	info tem;
	int n,ans = 0;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>tem.val;
		a.push(tem);
	}
	for(int i = 1;i < n;i++)
	{
		tem.val = 0;
		tem.val += a.top().val; a.pop();
		tem.val += a.top().val; a.pop();
		ans += tem.val; a.push(tem);
	}
	cout<<ans<<endl;
	return 0;
}

