#include<iostream>
#include<algorithm>
using namespace std;

int N;
int map[4][4];
int visited[4][4];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans;

void dfs(int couple, int x, int y, int sum) {
	if (couple == 4) { //최대 4쌍임
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; //Out of bound
		if (visited[nx][ny] == 1) continue; //이미 묶인 나무

		visited[nx][ny] = 1; //visited check
		sum += map[nx][ny]; //아름다움 적립

		ans = max(ans, sum); //최대 아름다움 확인

		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				if (visited[r][c] == 1) continue; //Alreadt vistied
				visited[r][c] = 1;
				dfs(couple + 1, r, c, sum + map[r][c]);
				visited[r][c] = 0;
			}
		}

		visited[nx][ny] = 0; //visited Uncheck
		sum -= map[nx][ny]; //아름다움 빼기
	}
}

int main(int argc, char** argv)
{

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			visited[i][j] = 1;
			dfs(0, i, j, map[i][j]);
			visited[i][j] = 0;
		}
	}

	cout << ans;

	return 0;
}