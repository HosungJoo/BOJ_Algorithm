#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

struct core {
	int x;
	int y;
};

int N;
int map[12][20][20];
int dx[] = { -1,1,0,0,0 };
int dy[] = { 0,0,-1,1 };
int max_core_cnt;
int min_length;
vector<core>cores;

void init() {
	memset(map, 0, sizeof(map));
	cores.clear();
	max_core_cnt = 0;
	min_length = 21e8;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[0][i][j];
			if (i == 0 || j == 0 || i == N - 1 || j == N - 1) continue;
			if (map[0][i][j] == 1) cores.push_back({ i,j });
		}
	}
}

void dfs(int cur_idx, int cur_core_cnt, int cur_length) {
	if (cur_core_cnt + (cores.size() - cur_idx) < max_core_cnt) return;
	if(cur_idx == cores.size()){
		//가장 많은 코어 갯수보다 많음
		if (max_core_cnt < cur_core_cnt) {
			max_core_cnt = cur_core_cnt;
			min_length = cur_length;
		}
		else if (max_core_cnt == cur_core_cnt) {
			//가장 많은 코어 중 길이가 짧은 거 
			min_length = min(min_length, cur_length);
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		core now = cores[cur_idx];
		int nx = now.x;
		int ny = now.y;

		bool pos_connect = false;
		int temp_length = 0;
		//이전 단계 map 가져오기
		memcpy(map[cur_idx + 1], map[cur_idx], sizeof(map[cur_idx]));

		while (1) {
			nx += dx[i];
			ny += dy[i];

			//전선이나 코어에 닿음
			if (map[cur_idx + 1][nx][ny] > 0) {
				break;
			}

			//경계에 닿음
			if (nx == 0 || ny == 0 || nx == N - 1 || ny == N - 1) {
				pos_connect = true;
				map[cur_idx + 1][nx][ny] = 2;
				temp_length++;
				break;
			}

			temp_length++;
			map[cur_idx + 1][nx][ny] = 2;
		}

		if (pos_connect) {//연결됨
			dfs(cur_idx + 1, cur_core_cnt + 1, cur_length + temp_length);
		}
		else { //연결 안됨
			dfs(cur_idx + 1, cur_core_cnt, cur_length);
		}
	}
}

void solve() {
	dfs(0, 0, 0);
}

int main() {
	
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " << min_length << "\n";
	}




	return 0;
}