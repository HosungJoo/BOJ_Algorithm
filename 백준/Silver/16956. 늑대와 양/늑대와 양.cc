#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

struct wolf {
	int x;
	int y;
};

int R, C;
char map[501][501];
bool flag;
bool visited[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void makefense(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if (map[nx][ny] != '.') continue;

		map[nx][ny] = 'D';
	}
}

void bfs(int x, int y) {
	queue<wolf> q;
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		wolf now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

			if (map[nx][ny] == 'S') {
				flag = 1;
				return;
			}

			if (visited[nx][ny]) continue;
			if (map[nx][ny] == 'D') continue;

			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {

	cin >> R >> C;

	for (int i = 0; i < R; i++) cin >> map[i];
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'S') makefense(i, j);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'W') bfs(i, j);
		}
	}

	if (flag) cout << 0;
	else {
		cout << 1 << "\n";
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
	}
	
	return 0;
}