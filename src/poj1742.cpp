#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 105
#define MAX_M 100005
using namespace std;
int n; //硬币的种类数
int m; //目标价格
int a[MAX_N]; //硬币的种类
int c[MAX_N]; //每种硬币的个数
int dp[MAX_M]; //dp[i+1][j]代表用前i种数加和得到j时第i种数最多剩余多少个（不能加和得到j的情况下为-1）
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if( n==0 && m==0 ) break;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>c[i];
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<=m;j++)
            {
                if(dp[j]>=0)
                    dp[j]=c[i];
                else if(j<a[i] || dp[j-a[i]]<=0)
                    dp[j]=-1;
                else
                    dp[j]=dp[j-a[i]]-1;
            }
        int answer=count_if(dp+1,dp+1+m,bind2nd(greater_equal<int>(),0));
        cout<<answer<<endl;
    }
    return 0;
}
