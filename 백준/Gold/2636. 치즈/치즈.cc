#include <iostream>
#include <queue>

using namespace std;

struct chz {
	int x;
	int y;
};

int N, M;
int size_chz;
int map[150][150];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs() {
	queue<chz>q;
	int visited[150][150] = { 0, };

	int melt_chz = 0;
	int cur_chz = size_chz;

	q.push({ 0,0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		chz now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 1) { //치즈를 만나면
				map[nx][ny] = 0;
				visited[nx][ny] = 2;
				size_chz--; //치즈 사라짐
				melt_chz++;
				continue;
			}
			if (visited[nx][ny] >= 1) continue;
			
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}

	if (melt_chz == cur_chz) {
		return melt_chz;
	}
	else return 0;
}

int main() {

	cin >> N >> M;

	int ans_tm = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) size_chz += 1;
		}
	}

	//치즈 가장 자리 찾으러 bfs
	int last_chz = 0;
	while (1) {
		int is_last = bfs();
		ans_tm++;
		if (is_last != 0) {
			last_chz = is_last;
			break;
		}
	}

	cout << ans_tm<< "\n" << last_chz;
	
	

	

	return 0;
}