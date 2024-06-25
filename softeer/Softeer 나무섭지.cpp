#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/*
BFS를 하되 유령을 먼저 가게 해서 남우가 가도 의미가 있는지 확인 시켰다
유령은 따로 방문배열 없이 map에 침몰시키면서 방문표시했다
중간에 방문배열 x,y잘못 넣은거랑 어디서 return시켜야 오류없이 되는지에 대해 시간을 많이 잡아먹음
로직 자체는 할만한듯
*/

struct info {
	int x;
	int y;
	char state;
};

int n, m;
char map[1002][1002];
int visited[1002][1002];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

info namw; //남우
vector<info>ghost;

void bfs() {
	queue<info>q;

	//유령 먼저 넣기
	for (int i = 0; i < ghost.size(); i++) {
		q.push(ghost[i]);
	}
	//남우 넣기
	q.push(namw);
	visited[namw.x][namw.y] = 1;

	while (!q.empty()) {
		info now = q.front();
		char state = now.state; //남우인지 유령인지
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; //out of bound
			if (state == 'N') { //남우라면
				if (map[nx][ny] == '#') continue; //벽이면 못감
				if (map[nx][ny] == 'G') continue; //유령이 있으면 못감
				if (visited[nx][ny] == 1) continue;//방문한 곳이면 안감
				if (map[nx][ny] == 'D') { //도착지가면 끝!
					cout << "Yes";
					return;
				}
				visited[nx][ny] = 1;
				q.push({ nx,ny,'N' });
			}
			else if (state == 'G') { //유령이라면
				if (map[nx][ny] == 'G') continue; //동선 겹침
				map[nx][ny] = 'G'; //유령이 감
				q.push({ nx,ny,'G' });
			}
		}
	}
	cout << "No";

}

int main(int argc, char** argv)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	//남우 출구 유령 찾기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'N') namw = { i,j,'N' };
			else if (map[i][j] == 'G') ghost.push_back({ i,j,'G' });
		}
	}

	bfs();

	return 0;
}