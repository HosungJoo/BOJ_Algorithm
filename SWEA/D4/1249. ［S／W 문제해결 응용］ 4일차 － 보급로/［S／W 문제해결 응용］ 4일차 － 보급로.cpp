#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct recover {
	int x;
	int y;
	int cost;
	bool operator<(recover right) const{
		if (cost < right.cost) return false;
		else if (cost > right.cost) return true;
		else return false;
	}
};

int T;
int N;
char map[100][100];
int dist[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void init() {
	memset(map, 0, sizeof(map));
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
}

void dijkstra(int x,int y) {
	priority_queue<recover>pq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = 2134567890;
		}
	}
	dist[x][y] = 0;
	pq.push({ x,y,0 });

	while (!pq.empty()) {
		recover now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			int nextcost = dist[now.x][now.y] + (map[nx][ny]-'0');
			if (dist[nx][ny] <= nextcost) continue;
			dist[nx][ny] = nextcost;
			pq.push({ nx,ny,nextcost });
		}
	}
}

void solve() {
	dijkstra(0, 0);
}

int main() {

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " << dist[N - 1][N - 1] << "\n";
	}

	return 0;
}