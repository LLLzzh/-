#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define MAXINT 2147482647LL
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

int b,ans,n,a[30],line[10][10],t;

void dfs(int x)
{
	if(x==n+1)
	{
		ans=max(ans,__builtin_popcount(b));
		return ;
	}
	dfs(x+1);
	if(b&a[x])return ;
	b^=a[x];
	dfs(x+1);
	b^=a[x];
}

int main()
{
	for(int i=1;i<=7;i++)
		for(int j=i+1;j<=8;j++)
			line[i][j]=line[j][i]=1<<(t++);
	n=read();
	for(int i=1;i<=n;i++)
	{
		int m=read(),l=read();
		for(int j=2;j<=m;j++)
		{
			int x=read();
			a[i]|=line[l][x];
			l=x;
		}
	}
	dfs(1);
	printf("%d\n",ans);

}
