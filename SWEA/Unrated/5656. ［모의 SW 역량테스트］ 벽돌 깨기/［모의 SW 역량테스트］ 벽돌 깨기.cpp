#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct info {
	int x;
	int y;
};

int N, W, H;
int map[20][20];
int cpmap[20][20];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int tot_bricks;
int ans;
int start[4];

void init() {
	memset(map, 0, sizeof(map));
	memset(cpmap, 0, sizeof(cpmap));
	tot_bricks = 0;
	ans = 21e8;
	for (int i = 0; i < 4; i++) start[i] = -1;
}

void input() {
	cin >> N >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];

			if (map[i][j] > 0) {
				tot_bricks++;
			}
		}
	}
}

int crack() {
	int left_bricks = tot_bricks;
	/*for (int i = 0; i < N; i++) cout << start[i] << " ";
	cout << "\n";*/

	for (int i = 0; i < N; i++) {

		//벽돌부스기
		int visited[20][20] = { 0 };
		queue<info>q;
		int x = 0;
		int y = start[i];

		for (int j = 0; j < H; j++) {
			if (cpmap[j][y] > 0) {
				q.push({ j,y });
				visited[j][y] = 1;
				break;
			}
		}

		while (!q.empty()) {
			info now = q.front();
			int splash = cpmap[now.x][now.y] - 1;
			left_bricks--;
			cpmap[now.x][now.y] = 0;
			q.pop();

			if (splash > 0) {
				for (int j = 0; j < 4; j++) {
					int nx = now.x;
					int ny = now.y;

					for (int k = 0; k < splash; k++) {
						nx += dx[j];
						ny += dy[j];

						if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
						if (cpmap[nx][ny] == 0) continue;
						if (visited[nx][ny] == 1) continue;
						visited[nx][ny] = 1; 
						q.push({ nx,ny });
					}
				}
			}
		}

		//중력
		for (int j = 0; j < W; j++) {
			int maxH = H - 1;
			for (int k = H - 1; k >= 0; k--) {

				if (cpmap[k][j] != 0) {
					int tmp = cpmap[k][j];
					cpmap[k][j] = 0;
					cpmap[maxH][j] = tmp;
					maxH--;
				}

			}
		}

		/*for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				cout << cpmap[h][w] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

	}
	/*cout << left_bricks << "\n";*/
	return left_bricks;
}

void dfs(int lv) {
	if (ans == 0) {
		return;
	}
	if (lv == N) {
		memcpy(cpmap, map, sizeof(map));
		ans = min(ans, crack());
		return;
	}
	for (int i = 0; i < W; i++) {
		start[lv] = i;
		dfs(lv + 1);
		start[lv] = -1;
	}
}

void solve() {
	dfs(0);
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