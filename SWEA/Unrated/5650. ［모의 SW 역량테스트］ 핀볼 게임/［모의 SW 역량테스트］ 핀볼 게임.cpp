#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int N;
int map[100][100];
int ans;
vector<pair<int, int>>wmhall[11];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


void init() {
	memset(map, 0, sizeof(map));
	ans = 0;
	for (int i = 6; i < 11; i++) wmhall[i].clear();
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 6) //웜홀 저장
				wmhall[map[i][j]].push_back({ i,j });
		}
	}
}


void finball(int x, int y, int dir) {
	int score = 0;
	int sx = x;
	int sy = y;
	while (1) {
		//방향으로 계속 직진
		x += dx[dir];
		y += dy[dir];
		if (sx == x && sy == y) {
			ans = max(ans, score);
			return;
		}
		//벽
		if (x == N || y == N || x < 0 || y < 0) {
			ans = max(ans, score * 2 + 1);
			return;
		}
		if (map[x][y] == 0) continue; //계속 진행
		//웜홀
		if (map[x][y] >= 6) {
			for (int i = 0; i < wmhall[map[x][y]].size(); i++) {
				int tx = wmhall[map[x][y]][i].first;
				int ty = wmhall[map[x][y]][i].second;

				if (tx == x && ty == y) continue;
				else {
					x = tx;
					y = ty;
					break;
				}
			}
			continue;
		}
		else if (map[x][y] >= 1) { //장애물
			if (map[x][y] == 5) {
				ans = max(ans, score * 2 + 1);
				return;
			}
			else if (map[x][y] == 4) {
				if (dir == 1) dir = 2;
				else if (dir == 3) dir = 0;
				else {
					ans = max(ans, score * 2 + 1);
					return;
				}
			}
			else if (map[x][y] == 3) {
				if (dir == 3) dir = 1;
				else if (dir == 0) dir = 2;
				else {
					ans = max(ans, score * 2 + 1);
					return;
				}
			}
			else if (map[x][y] == 2) {
				if (dir == 0) dir = 3;
				else if (dir == 2) dir = 1;
				else {
					ans = max(ans, score * 2 + 1);
					return;
				}
			}
			else {
				if (dir == 1) dir = 3;
				else if (dir == 2) dir = 0;
				else {
					ans = max(ans, score * 2 + 1);
					return;
				}
			}
			score++;
		}
		else if (map[x][y] == -1) {//블랙홀
			ans = max(ans, score);
			return;
		}
	}
}


void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) {
				for (int d = 0; d < 4; d++) {
					finball(i, j, d);
				}
			}
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