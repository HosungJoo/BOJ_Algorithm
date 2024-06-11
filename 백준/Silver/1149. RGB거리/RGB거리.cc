#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[1000][3];
int dp[1000][3];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	//초기설정
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for (int i = 1; i < N; i++) {
		//R G B
		for (int j = 0; j < 3; j++) {
			//현재 단에 칠할 색깔 기준으로 이전에 색깔은 다른 것을 동적프로그래밍한다
			if (j == 0) { 
				dp[i][j] = min((cost[i][j] + dp[i - 1][1]), (cost[i][j] + dp[i - 1][2]));
			}
			else if (j == 1) {
				dp[i][j] = min((cost[i][j] + dp[i - 1][0]), (cost[i][j] + dp[i - 1][2]));
			}
			else {
				dp[i][j] = min((cost[i][j] + dp[i - 1][0]), (cost[i][j] + dp[i - 1][1]));
			}
		}
	}

	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));

	return 0;
}