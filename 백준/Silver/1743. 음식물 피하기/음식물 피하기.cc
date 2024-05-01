#include<iostream>
#include<queue>

using namespace std;

struct info {
	int x;
	int y;
};

int map[100][100];
int N, M, foods;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs(int x, int y) {
	queue<info>q;
	q.push({ x,y });
	int ft_size = 0;
	map[x][y] = 0;

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		ft_size++;

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 0) continue;

			map[nx][ny] = 0;
			q.push({ nx,ny });
		}
	}

	return ft_size;
}

int main() {

	int ans = 0;

	cin >> N >> M >> foods;

	for (int i = 0; i < foods; i++) {
		int x, y;
		cin >> x >> y;
		map[x-1][y-1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				ans = max(ans, bfs(i, j));
			}
		}
	}

	cout << ans;

	return 0;
}