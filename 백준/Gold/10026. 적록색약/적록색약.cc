#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct info {
	int x;
	int y;
};

int N;
char map[101][101];
int visited[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(int x, int y) {
	queue<info>q;
	visited[x][y] = 1;
	q.push({ x,y });
	char color = map[x][y];

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (map[nx][ny] != color) continue;
			if (visited[nx][ny] == 1) continue;

			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

}

void bbfs(int x, int y) {
	queue<info>q;
	visited[x][y] = 1;
	q.push({ x,y });
	char color = map[x][y];

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (color == 'B') {
				if (map[nx][ny] != color) continue;
			}
			else {
				if (map[nx][ny] == 'B') continue;
			}
			if (visited[nx][ny] == 1) continue;

			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	//적록색약 아닌 사람
	int SEE_RG_Area = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j);
				SEE_RG_Area++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	//적록색약
	int BLIND_RG_Area = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				bbfs(i, j);
				BLIND_RG_Area++;
			}
		}
	}

	cout << SEE_RG_Area << " " << BLIND_RG_Area;

	return 0;
}