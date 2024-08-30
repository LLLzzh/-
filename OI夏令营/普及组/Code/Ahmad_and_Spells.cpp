#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a[100005],b[100005];
ll n,m,k,x,s;

struct hero
{
    ll c,d;
    friend bool operator < (hero a,hero b)
    {
        return a.d<b.d;
    }
    hero(ll _c=0,ll _d=0) {c=_c,d=_d;}
};
hero h[100005];
vector <hero> ok;

void inp()
{
    ll i;

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(h,0,sizeof(h));
    ok.clear();

    scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&x,&s);

    for(i=1;i<=m;i++)
        scanf("%lld",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%lld",&b[i]);
    for(i=1;i<=k;i++)
        scanf("%lld",&h[i].c);
    for(i=1;i<=k;i++)
        scanf("%lld",&h[i].d);
}

void gao()
{
    ll i,now=0;

    sort(h+1,h+1+k);

    ok.push_back(hero(0,0));

    for(i=1;i<=k;i++)
    {
        if(h[i].c<=now) continue;
        now=max(now,h[i].c);

        ok.push_back(h[i]);
    }
}

ll les(ll p)
{
    // printf("you can use %lld to less %lld\n",(*--upper_bound(ok.begin(),ok.end(),hero(0,p))).d,(*--upper_bound(ok.begin(),ok.end(),hero(0,p))).c);
    return (*(--upper_bound(ok.begin(),ok.end(),hero(0,p)))).c;
}

ll calc()
{
    ll i,t,ans=9000000000000000233;

    a[0]=x,b[0]=0;

    for(i=0;i<=m;i++)  //use talent i
        if(s>=b[i])
        {
            if(n-les(s-b[i])>0) t=(n-les(s-b[i]))*a[i];
            else t=0;
            // printf("Use talent %lld t=%lld\n",i,t);

            ans=min(ans,t);
        }

    printf("%lld\n",ans);
}

void work()
{
    inp();
    gao();
    calc();
}

int main(void)
{
    ll t;
    scanf("%lld",&t);

    while(t--)
        work();
    
    return 0;
}