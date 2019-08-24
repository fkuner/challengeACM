#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define MAXN 351
using namespace std;
int way[MAXN][MAXN],dp[MAXN][MAXN];
int N;
void Input()
{
    cin>>N;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=i;j++)
            scanf("%d",&way[i][j]);
}
void Solve()
{
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=N;i++)
        for (int j=1;j<=i;j++)
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+way[i][j];
}
void Output()
{
    int ret=dp[N][1];
    for (int i=2;i<=N;i++)
        if (ret<dp[N][i]) ret=dp[N][i];
    cout<<ret<<endl;
}
int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
/*滚动数组优化版本
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define MAXN 351
using namespace std;
int way[MAXN],dp[MAXN];
int N;
void Input()
{
    cin>>N;
    memset(dp,0,sizeof(dp));
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=i; j++)
            scanf("%d",&way[j]);
        for (int j=i; j>=1; j--)
            dp[j]=max(dp[j],dp[j-1])+way[j];
    }
}
void Output()
{
    int ret=dp[1];
    for (int i=2; i<=N; i++)
        if (ret<dp[i]) ret=dp[i];
    cout<<ret<<endl;
}
int main()
{
    Input();
    Output();
    return 0;
}
*/

