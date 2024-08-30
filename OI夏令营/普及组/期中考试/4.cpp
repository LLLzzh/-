#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define MAXINT 2147482647LL
#define clr(x) memset(x,0,sizeof(x))
#define maxclr(x) memset(x,0x3f,sizeof(x))
#define abs(x) ((x)>=0?(x):-(x))
using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 1005

int f[M][105][105],n,w,l[M],r[M],t[M],T[M];

void trans2t2(int t1,int t2,int l1,int r1,int l2,int r2)
{
}

int main()
{
	n=read();w=read();
	maxclr(f);
	f[0][0][w]=0;
	l[1]=r[1]=w;T[0]=2;
	for(int i=2;i<=n+1;i++)
	{
		t[i]=read(),l[i]=read(),r[i]=read();
		T[t[i]]++;
		if(t[i-1]==t[i]&&l[i-1]>l[i])swap(l[i-1],l[i]),swap(r[i-1],r[i]);
	}
	for(int i=2;i<=n+1;i++)
	{
		if(T[t[i]]==2&&T[t[i-1]]==2)
		{
			for(int lp=l[i-2];lp<=r[i-2];lp++)
				for(int rp=l[i-1];rp<=r[i-1];rp++)
					for(int ln=l[i];ln<=r[i];ln++)
						for(int rn=l[i+1];rn<=r[i+1];rn++)
							f[t[i]][ln][rn]=min(f[t[i]][ln][rn],f[t[i-1]][lp][rp]+abs(lp-ln)+abs(rp-rn));

		}
		if(T[t[i]]==2&&T[t[i-1]]==1)
		{
			for(int j=0;j<=w;j++)
				for(int la=l[i-1];la<=r[i-1];la++)
					for(int ln=l[i];ln<=r[i];ln++)
						for(int rn=l[i+1];rn<=r[i+1];rn++)
							f[t[i]][ln][rn]=min(f[t[i]][ln][rn],min(f[t[i-1]][j][la]+abs(j-ln)+abs(la-rn),f[t[i-1]][la][j]+abs(la-ln)+abs(rn-j)));
		}
		if(T[t[i]]==1&T[t[i-1]]==2)
		{
			for(int lp=l[i-2];lp<=r[i-2];lp++)
				for(int rp=l[i-1];rp<=r[i-1];rp++)
					for(int la=l[i];la<=r[i];la++)
						{
							f[t[i]][lp][la]=min(f[t[i]][lp][la],f[t[i-1]][lp][rp]+abs(rp-la));
							f[t[i]][la][rp]=min(f[t[i]][la][rp],f[t[i-1]][lp][rp]+abs(lp-la));
						}
		}
		if(T[t[i]]==1&&T[t[i-1]]==1)
		{
			for(int j=0;j<=w;j++)
				for(int la=l[i-1];la<=r[i-1];la++)
					for(int no=l[i];no<=r[i];no++)
					{
						f[t[i]][j][no]=min(f[t[i]][j][no],f[t[i-1]][j][la]+abs(la-no));
						f[t[i]][no][j]=min(f[t[i]][no][j],f[t[i-1]][la][j]+abs(la-no));
						f[t[i]][la][no]=min(f[t[i]][la][no],f[t[i-1]][la][j]+abs(j-no));
						f[t[i]][no][la]=min(f[t[i]][no][la],f[t[i-1]][j][la]+abs(j-no));
					}
		}
	}
	int ans=INF;
	for(int i=0;i<=w;i++)
		for(int j=0;j<=w;j++)
			ans=min(ans,f[t[n+1]][i][j]);
	printf("%d\n",ans);
	return 0;
}
