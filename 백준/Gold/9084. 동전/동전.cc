#include<iostream>
#include<cstring>

using namespace std;

int N;
int M;
int coin[20];
int dp[10001];

void init() {
	memset(coin, 0, sizeof(coin));
	memset(dp, 0, sizeof(dp));
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	cin >> M;
}

void solve() {
	dp[0] = 1;
	for (int i = 0; i < N; i++) {

		for (int j = coin[i]; j <= M; j++) {
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}
	cout << dp[M] << "\n";

}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
	}
	

	return 0;
}