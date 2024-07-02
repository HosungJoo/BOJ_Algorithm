#include <iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct info {
	int x;
	int y;
};

int row, col;
char map[21][21];
int dist[11][11];
int area[10];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans;
info bot;
vector<info>dirty;

int bfs(info depart, info dest) {
	queue<info>q;
	int visited[21][21] = { 0, };
	q.push(depart);
	visited[depart.x][depart.y] = 1;

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		if (now.x == dest.x && now.y == dest.y) {
			return visited[now.x][now.y] - 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue; //out of bound
			if (map[nx][ny] == 'x') continue; //가구 못 지나감
			if (visited[nx][ny] > 0) continue; //이미 갔으면 안가도됨

			q.push({ nx,ny });
			visited[nx][ny] = visited[now.x][now.y] + 1;
		}
	}
	return -1;
}

void dfs(int rt, int pre, int di) {
	if (rt == dirty.size()) {
		ans = min(ans, di);
		return;
	}
	for (int i = 0; i < dirty.size(); i++) {
		if (area[i] == 1)continue;
		area[i] = 1;
		dfs(rt + 1, i+1, di + dist[pre][i+1]);
		area[i] = 0;
	}
}

int main() {



	while (1) {

		cin >> col >> row;
		if (row == 0 && col == 0) break; //종료 조건

		//init
		memset(map, 0, sizeof(map));
		memset(dist, 0, sizeof(dist));
		memset(area, 0, sizeof(area));
		dirty.clear();
		ans = 21e8;

		//input
		for (int i = 0; i < row; i++) {
			cin >> map[i];
		}

		//solve
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 'o') {
					bot = { i,j };
				}
				else if (map[i][j] == '*') {
					dirty.push_back({ i,j });
				}
			}
		}

		bool impossible = false; //청소를 못하는 곳 발생

		//처음 로봇지점 부터 더러운 곳
		for (int i = 0; i < dirty.size(); i++) {
			int tmp_dist = bfs(bot, dirty[i]);
			if (tmp_dist == -1) {
				impossible = true;
				break;
			}
			dist[0][i + 1] = tmp_dist;
		}

		if (impossible) {
			cout << -1 << "\n";
			continue;
		}

		//더러운 곳 끼리 확인
		for (int i = 0; i < dirty.size(); i++) {
			for (int j = i; j < dirty.size(); j++) {
				dist[i + 1][j + 1] = bfs(dirty[i], dirty[j]);
				dist[j + 1][i + 1] = dist[i + 1][j + 1];
			}
		}

		dfs(0, 0, 0);

		cout << ans << "\n";
		
	}

	return 0;
}