#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

struct micro {
	int x;
	int y;
	int size;
	int dir;
};

struct info {
	int size;
	int dir;
	bool operator<(info right) {
		if (size > right.size) return true;
		else return false;
	}
};

int N, M, K;
int ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<micro>crude;
vector<info>copys[100][100];

void init() {
	ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			copys[i][j].clear();
		}
	}
	crude.clear();
}

void input() {
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int x, y, corps, dir;
		cin >> x >> y >> corps >> dir;
		crude.push_back({ x,y,corps,dir - 1 });
	}
}

void solve() {
	for (int i = 0; i < M; i++) {
		//이동시작
		for (int i = 0; i < crude.size(); i++) {

			int nx = crude[i].x + dx[crude[i].dir];
			int ny = crude[i].y + dy[crude[i].dir];
			int crude_size = crude[i].size;
			int dir = crude[i].dir;

			//약품에 닿음
			if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) {
				if (crude_size / 2 == 0)
					continue;
				else {
					//반토막
					crude_size /= 2;
					//방향 변경
					if (dir == 0) dir = 1;
					else if (dir == 1) dir = 0;
					else if (dir == 2) dir = 3;
					else dir = 2;
				}
			}

			//복사 맵에 저장
			copys[nx][ny].push_back({ crude_size,dir });
		}

		//미생물 buffer 다 비우기
		crude.clear();

		//맵에 옮겨 담기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (copys[i][j].size() == 0) continue;
				sort(copys[i][j].begin(), copys[i][j].end());

				//총크기
				int totsize = 0;
				int dir = copys[i][j][0].dir;
				for (int k = 0; k < copys[i][j].size(); k++) {
					totsize += copys[i][j][k].size;
				}
				copys[i][j].clear();
				crude.push_back({ i,j,totsize,dir });
			}
		}
	}

	for (int i = 0; i < crude.size(); i++) {
		ans += crude[i].size;
	}

}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();

		cout << "#" <<tc<<" "<< ans << "\n";
	}


	return 0;
}