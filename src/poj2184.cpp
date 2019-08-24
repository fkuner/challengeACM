#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[200005];
const int inf = 1<<30;

int main()
{
    int n,s[200],f[200],i,j,ans;
    while(~scanf("%d",&n))
    {
        for(i = 0; i<=200000; i++)
            dp[i] = -inf;
        dp[100000] = 0;
        for(i = 1; i<=n; i++)
            scanf("%d%d",&s[i],&f[i]);
        for(i = 1; i<=n; i++)
        {
            if(s[i]<0 && f[i]<0)
                continue;
            if(s[i]>0)
            {
                for(j = 200000; j>=s[i]; j--)//如果s[i]为正数，那么我们就从大的往小的方向进行背包
                    if(dp[j-s[i]]>-inf)
                        dp[j] = max(dp[j],dp[j-s[i]]+f[i]);
            }
            else
            {
                for(j = s[i]; j<=200000+s[i]; j++) //为负数则需要反过来
                    if(dp[j-s[i]]>-inf)
                        dp[j] = max(dp[j],dp[j-s[i]]+f[i]);
            }
        }
        ans = -inf;
        for(i = 100000; i<=200000; i++) //因为区间100000~200000才是表示的整数，那么此时的i就是之前背包中的S，如果此时dp[i]也就是F大于等于0的话，我们再加上S（此时为i），然后减去作为界限的100000，就可以得到答案
        {
            if(dp[i]>=0)
                ans = max(ans,dp[i]+i-100000);
        }
        printf("%d\n",ans);
    }

    return 0;
}
