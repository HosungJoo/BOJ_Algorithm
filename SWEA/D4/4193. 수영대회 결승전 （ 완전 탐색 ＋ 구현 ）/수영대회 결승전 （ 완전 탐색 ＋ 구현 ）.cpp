#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct posi {
	int x;
	int y;
};

int T;
int N;
int ans;
int sea[15][15];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int visited[15][15];

posi depart;
posi dest;

void init() {
	memset(sea, 0, sizeof(sea));
	memset(visited, 0, sizeof(visited));
	ans = 2134567890;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sea[i][j];
		}
	}

	cin >> depart.x >> depart.y;
	cin >> dest.x >> dest.y;
}

void bfs(int x, int y) {
	queue<posi> q;
	q.push({x,y});
	visited[x][y] = 0;

	while (!q.empty()) {
		posi now = q.front();
		q.pop();

		if (now.x == dest.x && now.y == dest.y) {
			if (visited[now.x][now.y] < ans) {
				ans = visited[now.x][now.y];
			}
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (nx == depart.x && ny == depart.y) continue;
			if (sea[nx][ny] == 1) continue;
			
			int tmptime = visited[now.x][now.y];
			if (sea[nx][ny] == 2) {
				while (tmptime % 3 != 2) tmptime++;
			}

			if (visited[nx][ny] != 0) {
				if (tmptime + 1 > visited[nx][ny]) continue;
			}

			visited[nx][ny] = tmptime + 1;
			
			q.push({ nx,ny });
		}
	}
}

void solve() {
	bfs(depart.x, depart.y);
}

int main() {

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
		
		cout << "#" << tc << " ";

		if (ans == 2134567890) {
			cout << -1 << "\n";
		}
		else {
			cout<< ans << "\n";
		}
	}

	return 0;
}