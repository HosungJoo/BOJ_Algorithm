#include<iostream>

using namespace std;

long long dp[101];

int main()
{
	int T;
	cin >> T;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;

	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;
		for (int i = 5; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[N] << "\n";
	}
	

	return 0;
}