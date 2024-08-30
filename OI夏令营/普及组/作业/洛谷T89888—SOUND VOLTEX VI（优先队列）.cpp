# include <iostream>
using namespace std;
struct heap
{
	int a[1000],cnt = 0;
	void repair_up(int x)
	{
		if(x == 1) return ;
		if(a[x] < a[x/2])
		{
			swap(a[x],a[x/2]);
			repair_up(x/2);
		}
	}
	void repair_down(int x)
	{
		if(2*x > cnt) return ;
		if(2*x == cnt)
		{
			if(a[x] > a[2*x]) swap(a[x],a[2*x]);
			return ;
		}
		int tar = a[2*x] > a[2*x+1]?2*x+1:2*x;
		if(a[x] > a[tar])
		{
			swap(a[x],a[tar]);
			repair_down(tar);
		}
	}
	void pop()
	{
		swap(a[1],a[cnt]);
		cnt--;
		repair_down(1);
	}
	void push(long long x)
	{
		cnt++;
		a[cnt] = x;
		repair_up(cnt);
	}
	int top(){return a[1];}
	bool empty(){return cnt == 0;}
	int sum()
	{
		int ans = 0;
		for(int i = 1;i <= min(20,cnt);i++) ans += a[i];
		return ans;
	}
};

int main(void)
{
	heap a; int n,lv; char c;
	long long force,mark;
	cin>>n;
	while(n--)
	{
		cin>>c;
		if(c == 'P')
		{
			cin>>lv>>mark;
			force = 25*(lv+1)*mark;
			force /= 10000000;
			a.push(force);
			if(a.cnt == 21) a.pop();
		}
		else if(c == 'Q') cout<<a.sum()<<endl;
	}
	return 0;
}
