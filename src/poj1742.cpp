#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 105
#define MAX_M 100005
using namespace std;
int n; //Ӳ�ҵ�������
int m; //Ŀ��۸�
int a[MAX_N]; //Ӳ�ҵ�����
int c[MAX_N]; //ÿ��Ӳ�ҵĸ���
int dp[MAX_M]; //dp[i+1][j]������ǰi�����Ӻ͵õ�jʱ��i�������ʣ����ٸ������ܼӺ͵õ�j�������Ϊ-1��
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
