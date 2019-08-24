//poj 3191 ��ȫ��������
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 105
using namespace std;
long long a[MAX_N][1005]; //��ǰi����Ʒ������j�����ı����ж������
long long b[MAX_N][1005]; //a��ǰ18λ��b�Ǻ���18λ
unsigned long long Mod =1;
int main()
{
    int n,k;
    for(int i=0;i<18;i++)
        Mod *= 10;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        //�����ü�����Ʒ����������Ϊ0�ı���ʼ��ֻ��һ�ַ�ʽ
        for(int i=0;i<=k;i++)
            b[i][0]=1;
        for(int i=0;i<k;i++)
            for(int j=1;j<=n;j++)
            {
                if(j<i)
                {
                    a[i+1][j]=a[i][j];
                    b[i+1][j]=b[i][j];
                }
                else
                {
                    a[i+1][j]=a[i][j]+a[i+1][j-(i+1)]+(b[i][j]+b[i+1][j-(i+1)])/Mod;
                    b[i+1][j]=(b[i][j]+b[i+1][j-(i+1)])%Mod;
                }
            }
        if(a[k][n])
            printf("%lld",a[k][n]);
        printf("%lld\n",b[k][n]);
    }
    return 0;
}
