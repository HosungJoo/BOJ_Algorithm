#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N;
int map[25][25];
bool visited[25][25];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int>section;

int bfs(int x, int y) {
	queue<pair<int, int>>q;
	visited[x][y] = 1;
	q.push({ x,y });

	int cnt = 1;

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = nowx + dx[i];
			int ny = nowy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == 0) continue;

			visited[nx][ny] = 1;
			cnt++;
			q.push({ nx,ny });
		}
	}
	return cnt;
}

int main() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%01d", &map[i][j]);
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				int scale = bfs(i, j);
				cnt++;
				section.push_back(scale);
			}
		}
	}

	sort(section.begin(), section.end());

	cout << cnt << "\n";
	for (int i = 0; i < section.size(); i++) {
		cout << section[i] << "\n";
	}

	return 0;
}