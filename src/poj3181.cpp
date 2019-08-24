//poj 3191 完全背包问题
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 105
using namespace std;
long long a[MAX_N][1005]; //用前i个物品，填满j容量的背包有多少种填法
long long b[MAX_N][1005]; //a是前18位，b是后面18位
unsigned long long Mod =1;
int main()
{
    int n,k;
    for(int i=0;i<18;i++)
        Mod *= 10;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        //无论用几个物品，填满容量为0的背包始终只有一种方式
        for(int i=0;i<=k;i++)
            b[i][0]=1;
        for(int i=0;i<k;i++)
            for(int j=1;j<=n;j++)
            {
                if(j<i)
                {
                    a[i+1][j]=a[i][j];
                    b[i+1][j]=b[i][j];
                }
                else
                {
                    a[i+1][j]=a[i][j]+a[i+1][j-(i+1)]+(b[i][j]+b[i+1][j-(i+1)])/Mod;
                    b[i+1][j]=(b[i][j]+b[i+1][j-(i+1)])%Mod;
                }
            }
        if(a[k][n])
            printf("%lld",a[k][n]);
        printf("%lld\n",b[k][n]);
    }
    return 0;
}
