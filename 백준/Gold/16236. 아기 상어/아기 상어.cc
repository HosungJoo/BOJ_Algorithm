#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


//처음 상어의 크기는 2
//자신의 크기와 같은 수의 물고기를 먹으면 크기가 1 커짐
//크기가 같으면 못먹지만 지나갈 수 있음
//거리가 가까운 물고기가 많다면 가장 위에 가장 왼쪽 물고기를 먹음
struct info {
	int x;
	int y;
	int dist;
	bool operator<(info right)const {
		if (dist < right.dist) return false;
		else if (dist > right.dist) return true;
		else {
			if (x < right.x) return false;
			else if (x > right.x) return true;
			else {
				if (y < right.y) return false;
				else if (y > right.y) return true;
				else return false;
			}
		}
	}
};

int map[21][21];
int N;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
info baby_shark;
int eat;
int b_size = 2;
int tot_eat;

int dijkstra() {
	priority_queue<info>pq;
	int visited[21][21] = { 0, };


	pq.push(baby_shark);
	visited[baby_shark.x][baby_shark.y] = 1;

	while (!pq.empty()) {
		info now = pq.top();
		pq.pop();

		if (b_size > map[now.x][now.y] && map[now.x][now.y] != 0) {//먹을 수 있으면 먹는다
			eat++;
			tot_eat++;
			if (eat == b_size) {
				b_size++;
				eat = 0;
			}
			map[now.x][now.y] = 0;
			baby_shark = { now.x,now.y,0 };
			return visited[now.x][now.y] - 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; // out of bound
			if (map[nx][ny] > b_size) continue; //상어보다 큰 물고기는 못 지나감
			if (visited[nx][ny] > 0) continue; // 거리가 짧은 대로

			visited[nx][ny] = visited[now.x][now.y] + 1;
			pq.push({ nx,ny,visited[nx][ny] });
		}
	}
	return -1;
}

int main() {

	cin >> N;

	int fishes = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				baby_shark = { i,j,0 };
				map[i][j] = 0;
			}
			else if (map[i][j] > 0) fishes++;
		}
	}

	int tm = 0;

	while (1) {
		if (tot_eat == fishes) break;
		int tmp = dijkstra();
		if (tmp == -1) {
			break;
		}
		tm += tmp;
	}

	cout << tm;

	return 0;
}