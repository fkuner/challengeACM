#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<float> Q;
bool cmp(int a,int b);
int main()
{
    int n;
    float tmp,tmp1,tmp2,tmp3;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        Q.push(tmp);
    }
    while(Q.size()!=1)
    {
        tmp1=Q.top();
        Q.pop();
        tmp2=Q.top();
        Q.pop();
        tmp3=2*sqrt(tmp1*tmp2);
        Q.push(tmp3);
    }
    printf("%.3f",Q.top());
    return 1;
}
