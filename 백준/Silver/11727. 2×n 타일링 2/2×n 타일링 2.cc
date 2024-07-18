#include<iostream>

using namespace std;

//dp[1] = 1,dp[2] = 3,dp[3] = 5, dp[4] = 11
// 2X1 1개 * 2X(N-1) + 1X2 2개 * 2X(N-2) + 2X2 1개 * 2X(N-2)
//점화식 잘 생각해야함 개어려움

int N;
int dp[1001];

int main()
{
	cin >> N;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 2] + dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[N];
	
	return 0;
}