#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
using namespace std;
typedef long long ll;
const ll M=1000000;
ll dp[1005][100005]; //dp[i+1][j]表示从前i种物品中取出j个的组合总数
int A[1005]; //每个家庭蚂蚁个数
int main()
{
    int t,a,s,b,tmp,ans;
    while(scanf("%d%d%d%d",&t,&a,&s,&b)!=EOF)
    {
        memset(A,0,sizeof(A));
        //hash
        for(int i=0;i<a;i++)
        {
            scanf("%d",&tmp);
            A[tmp-1]++;
        }
        //memset(dp,0,sizeof(dp));
        for(int i=0;i<=t;i++)
            dp[i][0]=1;
        for(int i=0;i<t;i++)
            for(int j=1;j<=b;j++)
            {
                if(j-1-A[i]>=0)
                    dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-A[i]]+M)%M;
                else
                    dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%M;
            }
        ans=0;
        for(int j=s;j<=b;j++)
            ans = (ans + dp[t][j])%M;
        printf("%d\n",ans);
    }
    return 0;
}
