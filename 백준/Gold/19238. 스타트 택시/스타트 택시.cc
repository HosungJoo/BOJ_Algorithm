#include <iostream>
#include <queue>

using namespace std;

//손님을 도착지로 데려다 줄 때마다 연료가 충전
//연료가 다 소모되면 그날 업무 종료
//최단거리에 있는 승객을 선택 가장 위에 가장 왼쪽에 있는 승객이 우선순위를 가짐
//택시와 승객이 같은 위치에 서 있으면 최단 거리는 0
//연료는 한칸 이동시 1만큼 소모
//목적지로 이동시키면 승객을 태워 이동한 연료 소모량의 2배가 충전됨
//이동중 연료가 모두 소모되면 업무 종료
//이동시킨 동시에 연료가 바닥나면 실패 아님

struct info {
	int x;
	int y;
	int dist;
	bool operator<(info right) const {
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

int N; //지도 크기
int M; //승객 수
int fuel; //연료
int map[21][21];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
pair<int, int>dest[402];
info taxi;

int find_customer() {
	priority_queue<info>pq;
	int visited[21][21] = { 0, };

	visited[taxi.x][taxi.y] = 1;
	pq.push({ taxi.x,taxi.y,1 });

	while (!pq.empty()) {
		info now = pq.top();
		pq.pop();

		/*cout << "=========================================\n";
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << visited[i][j] << " ";
			}
			cout << "\n";
		}*/

		if (map[now.x][now.y] >= 2) { //승객 찾음
			fuel -= (now.dist - 1);
			taxi = { now.x,now.y,0 };

			if (fuel > 0) {
				int c_id = map[now.x][now.y];
				map[now.x][now.y] = 0;
				return c_id;
			}
			else return -1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx<1 || ny<1 || nx>N || ny>N) continue; //out of bound
			if (map[nx][ny] == 1) continue; //벽
			if (visited[nx][ny] > 0) continue; //지나간 곳 안가도됨

			visited[nx][ny] = visited[now.x][now.y] + 1;
			pq.push({ nx,ny,visited[nx][ny] });
		}
	}
	return -1;
}

int go_dest(int dst) {
	queue<info>q;
	int visited[21][21] = { 0, };

	q.push({ taxi.x,taxi.y,1 });
	visited[taxi.x][taxi.y] = 1;

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		if (now.x == dest[dst].first && now.y == dest[dst].second) {
			taxi = { now.x,now.y,0 };
			fuel -= (visited[now.x][now.y] - 1);

			if (fuel >= 0) {
				fuel += ((visited[now.x][now.y] - 1) * 2);
				return 1;
			}
			else return -1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx<1 || ny<1 || nx>N || ny>N) continue; //Out of Bound
			if (map[nx][ny] == 1) continue; //벽
			if (visited[nx][ny] > 0) continue;

			visited[nx][ny] = visited[now.x][now.y] + 1;
			q.push({ nx,ny, visited[nx][ny] });
		}
	}
	return -1;
}

int main() {

	cin >> N >> M >> fuel;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	//택시 위치 받기
	cin >> taxi.x >> taxi.y;

	//승객과 도착지
	int id = 2;
	for (int i = 0; i < M; i++) {
		int c_x, c_y, d_x, d_y;

		cin >> c_x >> c_y;
		map[c_x][c_y] = id;

		cin >> d_x >> d_y;
		dest[id] = { d_x,d_y };
		id++;
	}

	bool drive_complete = true;

	for (int i = 0; i < M; i++) {
		int can_drive_customer = find_customer();

		if (can_drive_customer == -1) {
			cout << can_drive_customer;
			drive_complete = false;
			break;
		}

		int success_drive = go_dest(can_drive_customer);

		if (success_drive == -1) {
			cout << success_drive;
			drive_complete = false;
			break;
		}
	}

	if (drive_complete) cout << fuel;

	return 0;
}