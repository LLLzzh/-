#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
#include<cctype>
#include<vector>
#include<queue>
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

#define M 100005

int first[M],next[M*10],to[M*10],t;

void addedge(int s,int v)
{
	next[++t]=first[s];
	first[s]=t;
	to[t]=v;
}

queue<int>Q;
int n,k,q,c[M],b[M],vis[M],ansmx,ansmi,ans;

void bfs()
{
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		for(int i=first[x];i;i=next[i])
		{
			if(!vis[to[i]])
			{
				vis[to[i]]=1;
				Q.push(to[i]);
			}
		}
	}
}

int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
		int m=read();
		for(int j=1;j<=m;j++)
		{
			int a=read();
			addedge(a,i);
		}
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		int x=read();
		if(c[x])b[c[x]]=1;
		Q.push(x);
		vis[x]=1;
	}
	bfs();
	for(int i=1;i<=n;i++)
		ans+=vis[i];
	ansmx=ansmi=n-ans;
	for(int i=1;i<=n;i++)
		if(c[i]&&!b[c[i]]&&!vis[i])ansmi--;
	printf("%d %d\n",ansmi,ansmx);
}
