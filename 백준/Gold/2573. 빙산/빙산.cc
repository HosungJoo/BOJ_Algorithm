#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct info {
	int x;
	int y;
	int height;
};

int N, M;
int map[300][300];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int visited[300][300];

vector<info>bingsan;

int bfs(info node, int cnt) {
	queue<info>q;
	memset(visited, 0, sizeof(visited));
	q.push({ node });
	visited[node.x][node.y] = 1;
	int piece_of_ices = 1;

	while (!q.empty()) {

		info now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx<0 || ny<0 || nx>N || ny>M) continue;
			if (visited[nx][ny] == 1) continue;
			if (map[nx][ny] <= 0) continue;

			q.push({ nx,ny,now.height });
			visited[nx][ny] = 1;
			piece_of_ices++;
		}
	}

	if (piece_of_ices == cnt) return 1;
	else return 0;
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) {
				bingsan.push_back({ i,j,map[i][j] });
			}
		}
	}

	int years = 0;

	while (1) {

		years++;

		for (int i = 0; i < bingsan.size(); i++) {

			info now = bingsan[i];

			if (now.height < 0) continue;

			for (int j = 0; j < 4; j++) {
				int nx = now.x + dx[j];
				int ny = now.y + dy[j];

				if (nx<0 || ny<0 || nx>N || ny>M) {
					continue;
				}

				if (map[nx][ny] == 0) {
					bingsan[i].height--;
				}
			}
		}

		int unmelt = 0;
		info node = {};

		for (int i = 0; i < bingsan.size(); i++) {
			info now = bingsan[i];

			if (now.x >= 0 && now.y >= 0) {
				if (now.height > 0) {
					map[now.x][now.y] = now.height;
					unmelt++;
					node = now;
				}
				else {
					map[now.x][now.y] = 0;
					bingsan[i].x = -1;
					bingsan[i].y = -1;
				}
			}
		}

		if (unmelt == 0) {
			cout << 0;
			break;
		}

		if (bfs(node, unmelt)==0) {
			cout << years;
			break;
		}

	}

	
	return 0;
}