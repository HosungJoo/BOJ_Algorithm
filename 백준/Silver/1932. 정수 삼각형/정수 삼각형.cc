#include <iostream>
#include <algorithm>

using namespace std;

int tri[500][500];
int n;
int dp[500][500];
int ans;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	dp[0][0] = tri[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) { //가장 왼쪽
				dp[i][j] = max(dp[i][j],dp[i - 1][j] + tri[i][j]);
			}
			else if (j == i) { //가장 오른쪽
				dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + tri[i][j]);
			}
			else { //나머지
				dp[i][j] = max(dp[i - 1][j - 1] + tri[i][j], dp[i - 1][j] + tri[i][j]);
			}
			ans = max(ans, dp[i][j]);
		}
	}

	cout << max(dp[0][0], ans);

	return 0;
}