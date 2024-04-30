#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct secom {
	int x;
	int y;
};

int N, cost;
int ans;
int map[21][21];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void init() {
	memset(map, 0, sizeof(map));
	ans = 0;
}

void input() {
	cin >> N >> cost;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int x, int y) {
	queue<secom>q;
	int visited[21][21] = { 0, };
	int K[22] = { 0, }; //범위당 cnt갯수
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		secom now = q.front();
		q.pop();

		K[visited[now.x][now.y]] += map[now.x][now.y];

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx<0 || ny<0 || nx>=N || ny>=N) continue;
			if (visited[nx][ny] != 0) continue;

			q.push({ nx,ny });
			visited[nx][ny] = visited[now.x][now.y] + 1;
		}
	}

	
	int tothome = 0;
	for (int i = 1; i <= 21; i++) {
		tothome += K[i];
		int loss = i * i + (i - 1) * (i - 1);
		if (tothome * cost - loss >= 0) {
			ans = max(ans, tothome);
		}
	}
	return;
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bfs(i, j);
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}