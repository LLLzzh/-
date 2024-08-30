#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

// dp[n][k] : score=n , k is upward

int dp[10005][7];

void move(int n,int k)
{
    int ans,i,j;

    for(i=1;i<=6;i++)
        if(i!=k && i+k!=7)
            dp[n+i][i]=min(dp[n+i][i],dp[n][k]+1);
}

void calc()
{
    int i,j;

    for(i=0;i<=10002;i++)
        for(j=1;j<=6;j++)
            dp[i][j]=23333333;

    dp[0][1]=0;

    for(i=0;i<=10002;i++)
        for(j=1;j<=6;j++)
            move(i,j);
}

void get()
{
    int x,i,ans=23333333;
    scanf("%d",&x);
    for(i=1;i<=6;i++)
        ans=min(ans,dp[x][i]);
    printf("%d\n",ans==23333333?-1:ans);
}

int main(void)
{
    int t;
    calc();

    scanf("%d",&t);
    while(t--)
        get();
    
    return 0;
}