#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct area {
	int x;
	int y;
};

struct bridge {
	int from;
	int to;
	int dist;
};

int N, M; 
int map[10][10]; 
int parent[7];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int visited[10][10];
vector<bridge>build; //섬과 섬사이 거리를 구조체정보로 갖는 vector

void init() { 
	for (int i = 0; i < 7; i++) parent[i] = i; 
}

int find(int tar) {
	if (tar == parent[tar]) return tar;
	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;
	parent[t2] = t1;
}

void defisland(int x, int y, int num) { //섬의 이름 부여
	queue<area> q;

	q.push({ x,y });
	visited[x][y] = 1;
	map[x][y] = num;

	while (!q.empty()) {
		area now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 0) continue;
			if (visited[nx][ny] == 1) continue;

			visited[nx][ny] = 1;
			map[nx][ny] = num;
			q.push({ nx,ny });
		}
	}
}

void makeBridge(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (map[nx][ny] == map[x][y]) continue;

		visited[nx][ny] = visited[x][y] + 1;

		while (1) {
			nx += dx[i];
			ny += dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
			if (map[nx][ny] == map[x][y]) break;

			visited[nx][ny] = visited[nx-dx[i]][ny-dy[i]] + 1;

			if (map[nx][ny] != map[x][y] && map[nx][ny] != 0) {
				if (visited[nx][ny] == 2) break;
				build.push_back({ map[x][y],map[nx][ny],visited[nx][ny] - 1 });
				break;
			}
		}

	}
}

bool cmp(bridge a, bridge b) {
	return a.dist < b.dist;
}

int main() {

	init();

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int numbering = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 1) continue;
			if (map[i][j] == 1) {
				defisland(i, j, numbering);
				numbering++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	
	//섬으로 섬까지 cost를 구조체로 만들어서 vector에 삽입
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0) {
				makeBridge(i, j);
				memset(visited, 0, sizeof(visited));
			}
		}
	}

	//sort
	sort(build.begin(), build.end(), cmp);

	//union
	int islandconnect = numbering - 2;
	int mindist = 0;
	int cnt = 0;

	for (bridge sel : build) {
		int from = sel.from;
		int to = sel.to;
		int dist = sel.dist;

		if (find(from) == find(to)) continue;
		setUnion(from, to);
		cnt++;
		mindist += dist;
		if (cnt == islandconnect) break;
	}

	int stand = find(1);
	bool flag = 1;

	for (int i = 1; i <= numbering-1; i++) {
		if (find(i) != stand) {
			flag = 0;
			break;
		}
	}

	if (flag) cout << mindist;
	else cout << -1;

	
	return 0;
}