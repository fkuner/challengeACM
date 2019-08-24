//poj3666 Marking the Grade
//给定一个序列，以最小代价将其变为单调不增或单调不减序列
//思路:DP+离散化
#include <iostream>
#include <cstdio>
#include <algorithm>
#define Abs(a) ((a>0)?(a):-(a))
using namespace std;
const int N=2005;
const long long int INF=(1<<60);
int n;
int a[N],b[N];
long long int dp[4][N];
void solve()
{
    for(int j=0;j<n;j++)
	{
		dp[0][j]= Abs(a[0]-b[j]);
	}
	for(int i=1;i<n;i++)
	{
		long long mn=dp[(i-1)&1][0];
		for(int j=0;j<n;j++)
		{
			mn=min(mn,dp[(i-1)&1][j]);
			dp[i&1][j]=Abs(a[i]-b[j])+mn;
		}
	}
	long long ans=dp[(n-1)&1][0];
	for(int i=1;i<n;i++)
		ans=min(ans,dp[(n-1)&1][i]);
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	solve();
	return 0;
}
