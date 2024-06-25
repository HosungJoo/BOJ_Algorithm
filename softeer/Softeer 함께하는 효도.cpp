#include<iostream>

using namespace std;

/*
nXn이 20X20이기도하고 3초까지만 하므로 일단 완탐 냄새가 남
무작정 주위에 큰 수를 따라가기에 누군가 수확한 땅 다음에 매우 큰 수를 배치할시 예외상황 발생
따라서 완전탐색을 이용하여 풀기로 결정
dijkstra도 생각해봤으나 어떻게 구현할지 감이 안와서 포기
풀고나니까 가능할 수도?
*/

struct info {
	int x;
	int y;
};

int n, m;
int map[21][21];
int visited[4][21][21];
info co_worker[4];
int totsum[4];
int ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


void dfs(int sec, int x, int y, int sum, int id) {

	//cout<<"ID: "<<id<<" Sec: "<<sec<<" Sum: "<<sum<<" "<<x<<" "<<y<<"\n";

	if (sec == 3) {
		totsum[id] = sum;
		if (id == m) {
			int tmp_sum = 0;
			for (int i = 1; i <= m; i++) {
				tmp_sum += totsum[i];
			}
			ans = max(ans, tmp_sum);
		}
		else {
			visited[id + 1][co_worker[id + 1].x][co_worker[id + 1].y] = 1;
			int next_harv = map[co_worker[id + 1].x][co_worker[id + 1].y];
			map[co_worker[id + 1].x][co_worker[id + 1].y] = 0;
			dfs(0, co_worker[id + 1].x, co_worker[id + 1].y, next_harv, id + 1);
			map[co_worker[id + 1].x][co_worker[id + 1].y] = next_harv;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx<1 || ny<1 || nx>n || ny>n) continue;
		if (visited[id][nx][ny] == 1) continue;

		visited[id][nx][ny] = 1;
		int harv_dummy = map[nx][ny];
		map[nx][ny] = 0;
		dfs(sec + 1, nx, ny, sum + harv_dummy, id);
		map[nx][ny] = harv_dummy;
		visited[id][nx][ny] = 0;
	}
}

int main(int argc, char** argv)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		co_worker[i] = { x,y };
	}

	int first_harv = map[co_worker[1].x][co_worker[1].y];
	visited[1][co_worker[1].x][co_worker[1].y] = 1;
	map[co_worker[1].x][co_worker[1].y] = 0;
	dfs(0, co_worker[1].x, co_worker[1].y, first_harv, 1);

	cout << ans;

	return 0;
}