#include <iostream>

using namespace std;

struct info {
	long long horz;
	long long vert;
	long long oth;
};

int N;
int map[32][32];
info dp[32][32];

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dp[0][1].horz = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j] == 1) continue;

			if (dp[i][j].horz > 0) { //가로
				if (j + 1 < N && map[i][j + 1] == 0) { //가로 밀기
					dp[i][j + 1].horz += dp[i][j].horz;
				}
				if (i + 1 < N && j + 1 < N && map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] == 0) { //대각선 밀기
					dp[i + 1][j + 1].oth += dp[i][j].horz;
				}
			}

			if (dp[i][j].vert > 0) { //세로
				if (i + 1 < N && map[i + 1][j] == 0) { //세로 밀기
					dp[i + 1][j].vert += dp[i][j].vert;
				}
				if (i + 1 < N && j + 1 < N && map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] == 0) { //대각선 밀기
					dp[i + 1][j + 1].oth += dp[i][j].vert;
				}
			}

			if (dp[i][j].oth > 0) { //대각선
				if (j + 1 < N && map[i][j + 1] == 0) { //가로 밀기
					dp[i][j + 1].horz += dp[i][j].oth;
				}
				if (i + 1 < N && map[i + 1][j] == 0) { //세로 밀기
					dp[i + 1][j].vert += dp[i][j].oth;
				}
				if (i + 1 < N && j + 1 < N && map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] == 0) { //대각선 밀기
					dp[i + 1][j + 1].oth += dp[i][j].oth;
				}
			}

		}
	}

	cout << dp[N - 1][N - 1].horz + dp[N - 1][N - 1].vert + dp[N - 1][N - 1].oth;


	return 0;
}