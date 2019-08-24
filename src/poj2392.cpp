/*poj2392 Space Elevator

    ͨ��������ţ������c_i����h_i�Ļ�ľ��ͨ������ÿ�ֻ�ľ���ܸ߹�a_i�����������߶ȡ�
    ˼·:DP���ز��ֺ�����
    dp[i+1][j]:=��ǰi�����Ӻ͵õ�jʱ��i���������ʣ����ٸ������ܼӺ͵õ�j�������Ϊ-1��
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=405;
const int MAX_K=40005;
struct Node{
    int h; //���ݸ߶�
    int c; //��������
    int a; //�������Ƹ߶�
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
