# include <iostream>
using namespace std;
class chess
{
	private:
		char *a;
		int n,range;
		int p[5][4] = {{3,8,4,9},{3,7,4,8},{1,7,2,8},{1,6,2,7},{0,6,1,7}};
	public:
		chess(int size)
		{
			range = n = size;
			a = new char [2*n+2];
			for(int i = 0;i < n;i++) a[i] = 'o';
			for(int i = n;i < 2*n;i++) a[i] = '*';
			a[2*n] = a[2*n+1] = '-';
		}
		~chess(){delete a;}
		void show() {cout<<a<<endl;}
		void solve()
		{
			if(range == 4)
			{
				show();
				for(int i = 0;i < 5;i++)
				{
					swap(a[p[i][0]],a[p[i][1]]);
					swap(a[p[i][2]],a[p[i][3]]);
					show();
				}
			}
			else
			{
				show();swap(a[range-1],a[2*range]);swap(a[range],a[2*range+1]);
				show();swap(a[range-1],a[2*range-2]);swap(a[range],a[2*range-1]);
				range--;  solve();
			}
		}
};
int main(void)
{
	int n; cin>>n;
	chess a{n};
	a.solve();
	return 0;
}
