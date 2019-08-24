//Memory Time
//468K   172MS

#include<iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int main(int i,int j)
{
	int n;
	while(cin>>n)
	{
		int **way=new int*[n+1];   //动态申请二维数组的第一维，每个元素都是一个一维数组的指针

		/*Input & Initial*/

		for(i=0;i<=n;i++)
		{
			way[i]=new int[i+2]; //动态申请二维数组的第二维，每一行的空间
			for(j=0;j<=i+1;j++)
				way[i][j]=0;   //不能用memset初始化

			if(i!=0)
				for(j=1;j<=i;j++)
					cin>>way[i][j];
		}

		/*Dp*/

		int max_weight=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
			{
				way[i][j] += max(way[i-1][j-1],way[i-1][j]);

				if(i==n && max_weight<way[i][j])
					max_weight=way[i][j];
			}

		cout<<max_weight<<endl;

		delete[] way;
	}
	return 0;
}
