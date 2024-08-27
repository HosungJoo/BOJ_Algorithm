#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct info{
	int x;
	int y;
};

int N, M;
int map[10][10];
vector<info>virus;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int wallArea;
int ans;

int bfs() {
	queue<info>q;
	int visited[10][10] = { 0, };
	int virusArea = 0;

	//초기 바이러스 push
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		visited[virus[i].x][virus[i].y] = 1;
		++virusArea; //영역 count
	}

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 1) continue;
			if (visited[nx][ny] == 1) continue;

			visited[nx][ny] = 1;
			++virusArea; //영역 count
			q.push({ nx,ny });
		}
	}
	return virusArea;
}

void dfs(int wall,int x) {
	if (wall == 3) {
		int virusArea = bfs();
		ans = max(ans, N * M - virusArea - wallArea - 3);
		return;
	}
	for (int i = x; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) continue; //벽 또는 바이러스면 넘어감
			//벽 세우기
			map[i][j] = 1;
			dfs(wall + 1, i);
			map[i][j] = 0;
		}
	}
}

int main() {

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (map[i][j] == 1) {
				++wallArea;
			}
		}
	}

	dfs(0,0);

	cout << ans;


	return 0;
}