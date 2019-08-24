/*poj2392 Space Elevator

    通天塔：奶牛们想用c_i个高h_i的积木造通天塔，每种积木不能高过a_i，求塔的最大高度。
    思路:DP多重部分和问题
    dp[i+1][j]:=用前i种数加和得到j时第i种数最多能剩余多少个（不能加和得到j的情况下为-1）
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=405;
const int MAX_K=40005;
struct Node{
    int h; //电梯高度
    int c; //电梯数量
    int a; //电梯限制高度
    bool operator <(const Node &tmp) const
    {
        return a<tmp.a;
    }
}node[MAX_N];
int n;
int dp[MAX_N+1][MAX_K+1];
void solve()
{
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=MAX_K;j++)
        {
            if(dp[i][j]>=0)
                dp[i+1][j]=node[i].c;
            else if(j<node[i].h || dp[i+1][j-node[i].h]<=0 || j>node[i].a)
                dp[i+1][j]=-1;
            else
                dp[i+1][j]=dp[i+1][j-node[i].h]-1;
        }
    }
    int ans=-1;
    for(int i=0;i<=MAX_K;i++)
    {
        if(dp[n][i]!=-1)
            ans=max(ans,i);
    }
    cout<<ans<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>node[i].h>>node[i].a>>node[i].c;
    sort(node,node+n);
    solve();
    return 0;
}
