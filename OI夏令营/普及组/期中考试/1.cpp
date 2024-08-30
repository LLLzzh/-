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
