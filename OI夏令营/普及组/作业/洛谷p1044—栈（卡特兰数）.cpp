# include <iostream>
using namespace std;
/*设 x 为当前出栈序列的最后一个，则x有n种取值

由于x是最后一个出栈的，所以可以将已经出栈的数分成两部分

比x小或者比x大

比x小的数有x-1个，所以这些数的全部出栈可能为f[x-1]

比x大的数有n-x个，所以这些数的全部出栈可能为f[n-x]

这两部分互相影响，所以一个x的取值能够得到的所有可能性为f[x-1] * f[n-x]

另外，由于x有n个取值，所以

ans = f[0]*f[n-1] + f[1]*f[n-2] + ... + f[n-1]*f[0]; */
int main(void)
{
	int n,a[20] = {0};
	cin>>n; a[0] = a[1] = 1;
	for(int i = 2;i < 20;i++)
		for(int j = 0;j < i;j++) a[i] += a[j] * a[i-j-1];
	cout<<a[n]<<endl;
	return 0;
}
