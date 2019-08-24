#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;
pair<int, int> stick[5000 + 16];
int dp[5000 + 16];	// dp[i] := ����Ϊi+1���½���������ĩβԪ�ص����ֵ
 int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> stick[i].first >> stick[i].second;
		}
		sort(stick, stick + n);
		memset(dp, -1, n * sizeof(int));
		for (int i = 0; i < n; ++i)
		{
			*lower_bound(dp, dp + n, stick[i].second, greater<int>()) = stick[i].second;
		}
		cout << lower_bound(dp, dp + n, -1, greater<int>()) - dp << endl;
	}
    return 0;
}
