#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 100005
#define MAX_M 1005
using namespace std;
typedef struct Node{
    int st;
    int ed;
    int value;
};
bool cmp(Node a,Node b)
{
    if(a.st == b.st)
        return a.ed < b.ed;
    else
        return a.st < b.st;
}
int main()
{
    int n,m,r;
    Node node[MAX_M];
    int dp[MAX_N]; //dp[i][j]表示前j个间隔内i空闲间隔中最大的效率
    cin>>n>>m>>r;
    for(int i=0;i<m;i++)
    {
        cin>>node[i].st>>node[i].ed>>node[i].value;
        node[i].ed+=r;
    }
    sort(node,node+m,cmp);
    for(int i=0;i<m;i++)
    {
        dp[i] = node[i].value;
        for(int j=0;j<i;j++)
        {
            if(node[j].ed <= node[i].st)
            {
                dp[i] = max(dp[i],dp[j]+node[i].value);
            }
        }
    }
    cout<<*max_element(dp,dp+m)<<endl;
    return 0;
}
