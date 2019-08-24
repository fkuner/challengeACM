#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=40005;
const int INF=40005;
int a[MAX_N]; //The two blocks' ports and their mapping
int dp[MAX_N]; //dpÊý×é
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            dp[i]=INF;
        }
        for(int i=0;i<n;i++)
        {
            *lower_bound(dp,dp+n,a[i])=a[i];
        }
        printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    }
    return 0;
}
