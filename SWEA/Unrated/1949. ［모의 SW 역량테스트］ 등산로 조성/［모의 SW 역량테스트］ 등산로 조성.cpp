#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int K;
int height;
int map[10][10];
int visited[10][10];
int ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void init() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	height = 0;
	ans = 0;
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > height) height = map[i][j]; //최대 봉우리 갱신
		}
	}
}

void dfs(int x,int y,int len,int shovel) {
	if (ans < len) ans = len; //등산로 갱신

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visited[nx][ny] == 1) continue;
		if (map[x][y] <= map[nx][ny]) { //다음 봉우리가 같거나 높다면
			int gap = map[nx][ny] - map[x][y]; //봉우리 차이를 구해서
			if (gap + 1 <= shovel) { //깍을 수 있다면
				map[nx][ny] -= (gap + 1); //깍기
				visited[nx][ny] = 1; //방문 처리

				dfs(nx, ny, len + 1, shovel - shovel); //등산로 생성

				visited[nx][ny] = 0; //방문 해제
				map[nx][ny] += (gap + 1); //복구
			}
		}
		else {
			visited[nx][ny] = 1; //방문 처리

			dfs(nx, ny, len + 1, shovel);//등산로 생성

			visited[nx][ny] = 0; //방문 해제
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (height == map[i][j]) {
				visited[i][j] = 1;
				dfs(i, j, 1, K);
				visited[i][j] = 0;
			}

		}
	}
}

int main()
{
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