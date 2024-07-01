#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

struct info {
	int x;
	int y;
	char type;
};

int row, col;
char map[1001][1001]; //1000X1000일때 바깥쪽 접근하려면 1001X1001 map이어야 가능 이거 안해서 한 번 실수남
int visited[1000][1000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
info sg;
vector<info>fire;

void init() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	fire.clear();
}

void input() {
	cin >> col >> row;
	for (int i = 0; i < row; i++) {
		cin >> map[i];
	}
	//불이랑 상근이 찾기
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == '@') {
				sg = { i,j,'@' };
			}
			else if (map[i][j] == '*') {
				fire.push_back({ i,j,'*' });
			}
		}
	}
}

void bfs() {
	queue<info>q;
	
	//불 먼저 붙이기
	for (int i = 0; i < fire.size(); i++) {
		q.push(fire[i]);
	}

	q.push(sg);
	visited[sg.x][sg.y] = 1;

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (now.type == '*') { //불이라면
				if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue; //불은 밖으로 못감
				if (map[nx][ny] == '#') continue; //벽이면 불이 안붙음
				if (map[nx][ny] == '*') continue; //불이 붙은 곳은 안가도됨
				map[nx][ny] = '*';
			}
			else if (now.type == '@') {
				if (nx < 0 || ny < 0 || nx >= row || ny >= col) { //탈출함
					cout << visited[now.x][now.y] << "\n";
					return;
				}
				else {
					if (map[nx][ny] == '#') continue; //벽은 못감
					if (map[nx][ny] == '*') continue; //불붙은데 못감
					if (visited[nx][ny] > 0) continue; //방문했으면 안감
					visited[nx][ny] = visited[now.x][now.y] + 1;
				}
			}

			q.push({ nx,ny,now.type });
		}
	}
	cout << "IMPOSSIBLE\n";
}

void solve() {
	bfs();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
	}
	
	return 0;
}
