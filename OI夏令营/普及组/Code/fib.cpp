#include <cstdio>

int mem[100005];

int fib(int n)
{
    if(n==1 || n==2) return 1;
    if(mem[n]) return mem[n];
    printf("Calc [%d]\n",n);
    return mem[n]=fib(n-2)+fib(n-1);
}

int main(void)
{
    fib(10);
    return 0;
}