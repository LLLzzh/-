#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

#define MAX 2000000000
#define MMAX 9000000000000000000

ll a[100005],b[100005];
ll n,m;

ll co(ll x)
{
    ll i,cost=0;

    for(i=1;i<=n;i++)
        if(a[i]<x) cost+=x-a[i];
    for(i=1;i<=m;i++)
        if(b[i]>x) cost+=b[i]-x;

    // printf("co(%lld)=%lld\n",x,cost);

    return cost;
}

ll ma=MMAX,mb=0;

void inp()
{
    ll i;
    scanf("%lld%lld",&n,&m);

    for(i=1;i<=n;i++) scanf("%lld",&a[i]),ma=min(ma,a[i]);
    for(i=1;i<=m;i++) scanf("%lld",&b[i]),mb=max(mb,b[i]);
}

void three()
{
    ll l=0,r=MAX,mid,mmid,i,ans=MMAX;

    while(r-l > 5)
    {
        // printf("[%lld,%lld]\n",l,r);
        mid=(l+r)/2;
        mmid=(mid+r)/2;

        if(co(mid)<co(mmid)) r=mmid;
        else l=mid;
    }

    for(i=l;i<=r;i++)
        ans=min(ans,co(i));

    printf("%lld\n",ans);
}


int main(void)
{
    inp();
    if(ma<mb) three();
    else printf("0\n");
    
    return 0;
}