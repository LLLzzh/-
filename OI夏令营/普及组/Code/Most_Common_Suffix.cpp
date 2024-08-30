#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

struct node
{
    int c;
    int son[30];
    node(){c=0;memset(son,0,sizeof(son));}
};
int cnt=0,ans[100005]={0};
vector <node> s;

void ins(char *a)
{
    int i,x=0,len=strlen(a),t;
    for(i=len-1;i>=0;i--)
    {
        t=a[i]-'a';
        if(!s[x].son[t]) s[x].son[t]=++cnt,s.push_back(node());
        x=s[x].son[t];
        // printf("x=%d\n",x);
    }
    s[x].c++;
}

void init()
{
    cnt=0;
    memset(ans,0,sizeof(ans));
    s.clear();
    s.push_back(node());
}

int dfs(int x,int dep)
{
    int i,sz=0;
    for(i=0;i<=26;i++)
        if(s[x].son[i]) sz+=dfs(s[x].son[i],dep+1);
    ans[dep]=max(ans[dep],sz+s[x].c);
    return sz+s[x].c;
}

char a[100005];
int n,q;

void inp()
{
    int i;
    scanf("%d%d",&n,&q);

    for(i=1;i<=n;i++)
    {
        scanf("%s",a);
        ins(a);
    }

}

void work()
{
    int x;
    init();
    inp();

    dfs(0,0);

    while(q--)
    {
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }

}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--)
    work();
    
    return 0;
}