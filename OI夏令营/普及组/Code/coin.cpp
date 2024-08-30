#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
    int f[105]={0},i,n=15;

    f[0]=0;

    for(int i=1;i<=n;i++)
        f[i]=233333333;

    for(int i=0;i<=n;i++)
    {
        printf("f[%d]=%d\n",i,f[i]);
        
        f[i+1] = min(f[i+1],f[i]+1);
        f[i+5] = min(f[i+5],f[i]+1);
        f[i+11] = min(f[i+11],f[i]+1);
    }

    return 0;
}