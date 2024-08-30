# include <iostream>
# include <cstdio>
using namespace std;
struct heap
{
	int a[100005],cnt = 0;
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
	void ins(int x)
	{
		cnt++;
		a[cnt] = x;
		repair_up(cnt);
	}
	int top(){return a[1];}
	bool empty(){return cnt == 0;}
	void show()
	{
		int k = cnt;
		for(int i = 0;i < k;i++)
		{
			cout<<top()<<(i == k-1?"\n":" ");
			pop();
		}
	}
};
int main(void)
{
	heap w;
	int n,k;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&k);
		w.ins(k);
	}
	w.show();
	return 0;
}
